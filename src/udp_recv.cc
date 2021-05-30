#include "utils.h"

int main(int argc, char* argv[])
{
    int sd;
    uint8_t buffer[PACKETSIZE];
    int frame_len;

    TRY((sd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)));

    while (1) {
        TRY(frame_len = recvfrom(sd, buffer, PACKETSIZE, 0, NULL, NULL));
        struct ether_header *ether_header = (struct ether_header*)buffer;
        struct ip* ip_header = (struct ip*)(buffer + ETH_HDRLEN);
        struct udphdr* udp_header = (struct udphdr*)(buffer + ETH_HDRLEN + IP4_HDRLEN);
        uint8_t *payload = (buffer + ETH_HDRLEN + IP4_HDRLEN +  UDP_HDRLEN);
        int sd;

        Hexdump(buffer, frame_len);
    }

}
