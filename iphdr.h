#include <pshpack1.h>
#ifndef __IPHDR
#define __IPHDR

#define ETHERTYPE_IP 0x0008   //IP Protocal  
#define ETHERTYPE_ARP 0x0608   //Address Resolution Protocal  
#define ETHERTYPE_REVARP 0x3508   //Reverse Address Resolution Protocal 逆地址解析协议

#define NPROT_MAC_ADDR_LEN 6
typedef struct _NDISPROT_ETH_HEADER
{
	unsigned char       DstAddr[NPROT_MAC_ADDR_LEN];
	unsigned char       SrcAddr[NPROT_MAC_ADDR_LEN];
	unsigned short      EthType;
} NDISPROT_ETH_HEADER;

typedef struct in6_addr {
	union {
		unsigned char  Byte[16];
		unsigned short Word[8];
	} u;
} IN6_ADDR, * PIN6_ADDR, FAR* LPIN6_ADDR;

//
// IPv4 Header (without any IP options)
//
typedef struct ip_hdr
{
	unsigned char  ip_vhl;        // 4-bit IPv4 version // 4-bit header length (in 32-bit words)
	unsigned char  ip_tos;           // IP type of service
	unsigned short ip_totallength;   // Total length
	unsigned short ip_id;            // Unique identifier 
	unsigned short ip_offset;        // Fragment offset field
	unsigned char  ip_ttl;           // Time to live
	unsigned char  ip_protocol;      // Protocol(TCP,UDP etc)
	unsigned short ip_checksum;      // IP checksum
	unsigned char   ip_srcaddr[4];       // Source address
	unsigned char   ip_destaddr[4];      // Source address
} IPV4_HDR, * PIPV4_HDR, FAR* LPIPV4_HDR;

#define IP_HL(ip)		(((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)		(((ip)->ip_vhl) >> 4)
#define IP_TL(ip)		((((ip)->ip_totallength) & 0xff00) >> 8)

//
// IPv6 Header
//
typedef struct ipv6_hdr
{
	unsigned long   ipv6_vertcflow;        // 4-bit IPv6 version
										   // 8-bit traffic class
										   // 20-bit flow label
	unsigned short  ipv6_payloadlen;       // payload length
	unsigned char   ipv6_nexthdr;          // next header protocol value
	unsigned char   ipv6_hoplimit;         // TTL 
	struct in6_addr ipv6_srcaddr;          // Source address
	struct in6_addr ipv6_destaddr;         // Destination address
} IPV6_HDR, * PIPV6_HDR, FAR* LPIPV6_HDR;

//
// IPv6 Fragmentation Header
//
typedef struct ipv6_fragment_hdr
{
	unsigned char   ipv6_frag_nexthdr;      // Next protocol header
	unsigned char   ipv6_frag_reserved;     // Reserved: zero
	unsigned short  ipv6_frag_offset;       // Offset of fragment
	unsigned long   ipv6_frag_id;           // Unique fragment ID
} IPV6_FRAGMENT_HDR, * PIPV6_FRAGMENT_HDR;

//
// Define the UDP header 
//
typedef struct udp_hdr
{
	unsigned short src_portno;       // Source port no.
	unsigned short dst_portno;       // Dest. port no.
	unsigned short udp_length;       // Udp packet length
	unsigned short udp_checksum;     // Udp checksum
} UDP_HDR, * PUDP_HDR;

/* TCP header */
typedef UINT tcp_seq;
typedef struct _TCPHeader {
	unsigned short th_sport;	/* source port */
	unsigned short th_dport;	/* destination port */
	tcp_seq th_seq;		/* sequence number */
	tcp_seq th_ack;		/* acknowledgement number */
	unsigned char th_offx2;	/* data offset, rsvd */
#define TH_OFF(th)      ((((th)->th_offx2) & 0xf0) >> 4)
	unsigned char th_flags;
#define TH_FIN 0x01
#define TH_SYN 0x02
#define TH_RST 0x04
#define TH_PUSH 0x08
#define TH_ACK 0x10
#define TH_URG 0x20
#define TH_ECE 0x40
#define TH_CWR 0x80
#define TH_FLAGS (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
	unsigned short th_win;		/* window */
	unsigned short th_sum;		/* checksum */
	unsigned short th_urp;		/* urgent pointer */
}TCPHeader, * PTCPHeader;

typedef struct _psd_header
{
	unsigned long saddr; //源地址
	unsigned long daddr; //目的地址
	char mbz;			//置空
	char ptcl;			//协议类型
	unsigned short tcpl; //TCP长度
}PSD_HEADER;


//#define __BIG_ENDIAN 1
#if __BIG_ENDIAN
/* The host byte order is the same as network byte order,
   so these functions are all just identity.  */
#define ntohl(x)    (x)
#define ntohs(x)    (x)
#define htonl(x)    (x)
#define htons(x)    (x)
#else
#define ntohl(x)    __bswap_32 (x)
#define ntohs(x)    __bswap_16 (x)
#define htonl(x)    __bswap_32 (x)
#define htons(x)    __bswap_16 (x)
#endif


#include <poppack.h>

#endif
