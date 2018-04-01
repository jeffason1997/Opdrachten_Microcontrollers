#include <avr/io.h>
#include <util/delay.h>
#define BIT(x) ( 1<<x )
#define DDR_SPI DDRB // spi Data direction register
#define PORT_SPI PORTB // spi Output register
#define SPI_SCK 1 // PB1: spi Pin System Clock
#define SPI_MOSI 2 // PB2: spi Pin MOSI
#define SPI_MISO 3 // PB3: spi Pin MISO
#define SPI_SS 0 // PB0: spi Pin Slave Select

void wait(int ms)
{
	for (int i=0; i<ms; i++)
	_delay_ms(1);
}

void spi_masterInit(void)
{
	DDR_SPI = 0xff;
	DDR_SPI &= ~BIT(SPI_MISO);
	PORT_SPI |= BIT(SPI_SS);
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1);
}

void spi_write( unsigned char data )
{
	SPDR = data; // Load byte --> starts transmission
	while( !(SPSR & BIT(SPIF)) ); // Wait for transmission complete
}
// Write a byte from master to slave and read a byte from slave - not used here
char spi_writeRead( unsigned char data )
{
	SPDR = data; // Load byte --> starts transmission
	while( !(SPSR & BIT(SPIF)) ); // Wait for transmission complete
	data = SPDR; // New received data (eventually, MISO) in SPDR
	return data; // Return received byte
}
// Select device on pinnumer PORTB
void spi_slaveSelect(unsigned char chipNumber)
{
	PORTB &= ~BIT(chipNumber);
}
// Deselect device on pinnumer PORTB
void spi_slaveDeSelect(unsigned char chipNumber)
{
	PORTB |= BIT(chipNumber);
}

// Initialize the driver chip (type MAX 7219)
void displayDriverInit()
{
	spi_slaveSelect(0); // Select display chip (MAX7219)
	spi_write(0x09); // Register 09: Decode Mode
	spi_write(0xFF); // -> 1's = BCD mode for all digits
	spi_slaveDeSelect(0); // Deselect display chip

	spi_slaveSelect(0); // Select dispaly chip
	spi_write(0x0A); // Register 0A: Intensity
	spi_write(0x0F); // -> Level F (in range [1..F])
	spi_slaveDeSelect(0); // Deselect display chip

	spi_slaveSelect(0); // Select display chip
	spi_write(0x0B); // Register 0B: Scan-limit
	spi_write(0x03); // -> 3 = Display digits 0..3
	spi_slaveDeSelect(0); // Deselect display chip

	spi_slaveSelect(0); // Select display chip
	spi_write(0x0C); // Register 0B: Shutdown register
	spi_write(0x01); // -> 1 = Normal operation
	spi_slaveDeSelect(0); // Deselect display chip
}
// Set display on ('normal operation')
void displayOn()
{
	spi_slaveSelect(0); // Select display chip
	spi_write(0x0C); // Register 0B: Shutdown register
	spi_write(0x01); // -> 1 = Normal operation
	spi_slaveDeSelect(0); // Deselect display chip
}
// Set display off ('shut down')
void displayOff()
{
	spi_slaveSelect(0); // Select display chip
	spi_write(0x0C); // Register 0B: Shutdown register
	spi_write(0x00); // -> 1 = Normal operation
	spi_slaveDeSelect(0); // Deselect display chip
}

void spi_writeWord ( unsigned char place, unsigned char value ) {
	spi_slaveSelect(0); 
	spi_write(place); 
	spi_write(value);
	spi_slaveDeSelect(0);
}

void spi_writeValue( int value ) {
	if(value>=0){
		spi_writeWord(1, (value % 10000) / 1000);
	} else {
		spi_writeWord(1,10);
	}

	spi_writeWord(2, (value % 1000) / 100);
	spi_writeWord(3, (value % 100) / 10);
	spi_writeWord(4, value % 10);
}

int main()
{
	DDRB=0x01; // Set PB0 pin as output for display select
	spi_masterInit(); // Initialize spi module
	displayDriverInit(); // Initialize display chip
	// clear display (all zero's)
	for (char i =1; i<=2; i++)
	{
		spi_slaveSelect(0); // Select display chip
		spi_write(i); // digit adress: (digit place)
		spi_write(0); // digit value: 0
		spi_slaveDeSelect(0); // Deselect display chip
	}
	wait(1000);
	// write 4-digit data
	for (char i =1; i<=2; i++)
	{
		spi_slaveSelect(0); // Select display chip
		spi_write(i); // digit adress: (digit place)
		spi_write(i); // digit value: i (= digit place)
		spi_slaveDeSelect(0); // Deselect display chip
		wait(1000);
	}
	wait(1000);
	return (1);
}