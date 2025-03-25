#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define MAX_SIZE_U48 281474976710656

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long int int64;

typedef struct mac_address {
	int64 m_addr:48; // var:num --> limits the size of a variable to a specific number of bytes
} mac_address_t;

mac_address_t generateMacAddress(void);
// char parseMacAddressToString(mac_address_t);
int main(int, char **);

int main(int argc, char **argv) {
	srand(getpid());
	mac_address_t mac;
	mac = generateMacAddress();
	printf("mac_address = %llx\n", (long long) mac.m_addr);
	return 0;
}

mac_address_t generateMacAddress(void) {
	int64 a, b;
	mac_address_t mac_addr_i, mac_addr_end; 
	// mac_address_t  mac_addr_start;
	a = (long) rand();
	b = (long) rand();
	mac_addr_i.m_addr = (a * b) % MAX_SIZE_U48;
	mac_addr_end.m_addr = mac_addr_i.m_addr >> 2;

	return mac_addr_end;
}

/*
char parseMacAddressToString(mac_address_t mac_addr) {
	char mac_addr_str[12 + 5 + 1];
	// sprintf(mac_addr_str, "%llx", mac_addr.m_addr);
	
}
*/

