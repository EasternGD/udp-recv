#include "utils.h"

int main(int argc, char* argv[])
{
    int sd;
    uint8_t buffer[PACKETSIZE];
    int frame_len;

    TRY((sd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))));

    while (1) {
        TRY(frame_len = recvfrom(sd, buffer, PACKETSIZE, 0, NULL, NULL));
        struct ether_header *ether_header = (struct ether_header*)buffer;
        struct ip* ip_header = (struct ip*)(buffer + ETH_HDRLEN);
        struct udphdr* udp_header = (struct udphdr*)(buffer + ETH_HDRLEN + IP4_HDRLEN);
        uint8_t *payload = (buffer + ETH_HDRLEN + IP4_HDRLEN +  UDP_HDRLEN);

        if (ip_header->ip_p != IPPROTO_UDP)
            continue;

        PrintEthernetHeader(ether_header);
        PrintIpHeader(ip_header);
        PrintUdpHeader(udp_header);

        Hexdump(payload, frame_len - (ETH_HDRLEN + IP4_HDRLEN + UDP_HDRLEN));
    }

}
