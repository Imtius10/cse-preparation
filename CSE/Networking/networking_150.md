# Networking Interview Preparation — 150 Questions & Answers

> **Purpose:** Job preparation for Junior Software Engineer, Backend, Full-Stack, SQA, DevOps, and Network-aware developer interviews.
>
> **Format:** Easy → Intermediate → Hard, with visual diagrams, real-life analogies, examples, and Linux commands.
>
> **Study rule:** First understand the visual/example, then memorize the **Key Point**.

---

# Table of Contents

1. [Networking Fundamentals — 1–30](#1-networking-fundamentals--130)
2. [OSI & TCP/IP — 31–55](#2-osi--tcpip--3155)
3. [TCP, UDP & Transport — 56–85](#3-tcp-udp--transport--5685)
4. [IP Addressing & Subnetting — 86–110](#4-ip-addressing--subnetting--86110)
5. [DNS, HTTP & Web Networking — 111–130](#5-dns-http--web-networking--111130)
6. [Mid/Hard Networking — 131–150](#6-midhard-networking--131150)
7. [Most Important Questions](#-20-questions-to-memorize-first)
8. [Practical Linux Networking Commands](#-practical-linux-networking-commands)
9. [Final Interview Cheat Sheet](#-final-interview-cheat-sheet)

---

# 1. Networking Fundamentals — 1–30

## 1. What is a computer network?

A **computer network** is a collection of connected devices that communicate and share resources.

### Real-life example

Think about a university:

```text
             University Network
                    |
       +------------+------------+
       |            |            |
     PC Lab       Server       Wi-Fi
       |            |            |
    Students     Database      Phones
```

Students can access the same internet, server, printer, or database because the devices are connected.

### Key Point

> Network = connected devices + communication + resource sharing.

---

## 2. What is a node?

A **node** is a device that participates in a network.

Examples:

```text
Laptop
Phone
Server
Router
Printer
IoT device
```

### Real life

Your laptop, Wi-Fi router, and phone are all nodes in your home network.

---

## 3. What is a network protocol?

A **protocol** is a set of rules that devices follow when communicating.

Real-life analogy:

Two people need a common language to communicate.

```text
Person A ---- English ----> Person B
```

Computers similarly use protocols:

```text
Browser ---- HTTP ----> Web Server
Computer ---- TCP ----> Server
Computer ---- DNS ----> DNS Server
```

Examples:

- HTTP
- HTTPS
- TCP
- UDP
- IP
- DNS
- DHCP
- SSH

### Key Point

> Protocol = communication rules.

---

## 4. What is an IP address?

An IP address is a logical address used to identify a network interface.

Example:

```text
192.168.1.10
```

### Real-life analogy

An IP address is similar to a house address.

```text
House address → identifies a house
IP address    → identifies a network interface
```

---

## 5. What is IPv4?

IPv4 is the fourth version of the Internet Protocol.

It uses **32-bit addresses**.

Example:

```text
192.168.1.10
```

IPv4 has:

```text
2^32 ≈ 4.29 billion
```

possible addresses.

---

## 6. What is IPv6?

IPv6 uses **128-bit addresses**.

Example:

```text
2001:db8::1
```

### Why IPv6?

IPv4 addresses are limited.

IPv6 provides an extremely large address space.

```text
IPv4 → 32 bits
IPv6 → 128 bits
```

---

## 7. What is a MAC address?

A MAC address is a Layer 2 address associated with a network interface.

Example:

```text
3C:52:82:AB:10:FF
```

### Real-life analogy

If IP is a house address, MAC is more like the identifier of the network interface/device on the local network.

### Key Point

```text
IP  → logical/network-layer address
MAC → link-layer address
```

---

## 8. IP address vs MAC address

| IP | MAC |
|---|---|
| Logical address | Link-layer address |
| Layer 3 | Layer 2 |
| Used for routing | Used for local delivery |
| Can change | Associated with NIC/interface |

### Visual

```text
        INTERNET
           |
      IP addresses
           |
        Router
           |
      MAC addresses
           |
   +-------+-------+
   |               |
 Laptop          Phone
```

---

## 9. What is LAN?

LAN = **Local Area Network**.

A LAN connects devices in a limited area.

Examples:

- Home
- Office
- Computer lab

```text
Laptop ----+
Phone -----+---- Switch/Wi-Fi ---- Router
PC --------+
```

---

## 10. What is WAN?

WAN = **Wide Area Network**.

It connects networks over larger geographical distances.

```text
Dhaka Office ---- ISP/Internet ---- Chattogram Office
```

The Internet is the most famous example of a WAN.

---

## 11. What is MAN?

MAN = **Metropolitan Area Network**.

It generally covers a city or metropolitan area.

Example:

```text
University A
      |
      +---- City Network ----+
                             |
University B ----------------+
```

---

## 12. What is PAN?

PAN = **Personal Area Network**.

Example:

```text
        Phone
        /   \
 Bluetooth   Bluetooth
    /           \
Earbuds       Smartwatch
```

---

## 13. What is bandwidth?

Bandwidth is the maximum capacity of a network connection.

Example:

```text
Internet package = 100 Mbps
```

This does **not** necessarily mean every download will always run at 100 Mbps.

### Real-life analogy

A road has a maximum capacity.

```text
Small road → low capacity
Highway    → high capacity
```

Bandwidth is like the width/capacity of the highway.

---

## 14. What is latency?

Latency is the time taken for data to travel between endpoints.

Example:

```text
Ping = 20 ms
```

### Real-life analogy

Two roads can have the same capacity but different travel times.

```text
Road A → 20 minutes
Road B → 2 hours
```

Low latency is especially important for:

- Online games
- Video calls
- Financial systems
- Real-time applications

---

## 15. What is throughput?

Throughput is the actual amount of data successfully transferred per unit of time.

```text
Bandwidth = theoretical capacity
Throughput = actual achieved transfer rate
```

Example:

```text
100 Mbps connection
Actual download = 75 Mbps

Bandwidth  = 100 Mbps
Throughput = 75 Mbps
```

---

## 16. What is a packet?

A packet is a unit of data transmitted through a packet-switched network.

Simplified:

```text
+----------------+----------------+
| Header         | Payload        |
+----------------+----------------+
```

The header contains control information.

The payload contains the actual data.

---

## 17. What is a frame?

A frame is a Layer 2 data unit.

Simplified:

```text
+---------+---------+---------+
| Header  |  Data   |Trailer |
+---------+---------+---------+
```

Ethernet uses frames.

---

## 18. What is a router?

A router connects different networks and forwards packets between them.

```text
Home LAN
   |
   | 192.168.1.0/24
   |
 Router
   |
   | ISP
   |
Internet
```

### Real-life analogy

A router is like a traffic controller deciding which road a vehicle should take.

---

## 19. What is a switch?

A switch connects devices within a LAN and forwards Ethernet frames using MAC addresses.

```text
          Switch
        /    |    \
      PC    PC   Printer
```

---

## 20. Router vs Switch

| Switch | Router |
|---|---|
| Mainly Layer 2 | Layer 3 |
| Uses MAC addresses | Uses IP addresses |
| Connects devices in a LAN | Connects different networks |
| Forwards frames | Forwards packets |

### Easy memory trick

> **Switch = same network**
>
> **Router = between networks**

---

## 21. What is a hub?

A hub is a basic Layer 1 device that repeats incoming signals to all ports.

```text
             Hub
          / / | \ \
        PC PC PC PC
```

If PC1 sends data, the hub repeats it to all connected ports.

A switch is smarter because it can selectively forward frames.

---

## 22. Hub vs Switch

### Hub

```text
PC1 → HUB → PC2
          ↘ PC3
          ↘ PC4
```

### Switch

```text
PC1 → SWITCH → PC2
```

The switch learns MAC addresses and can forward the frame only where needed.

---

## 23. What is a server?

A server provides services or resources to clients.

Examples:

```text
Web Server
Database Server
DNS Server
Mail Server
File Server
```

### Real-life example

When you open a website:

```text
Browser → Web Server
```

The web server returns the requested content.

---

## 24. What is a client?

A client requests services from a server.

Example:

```text
Browser = Client
Website backend = Server
```

```text
Client → Request → Server
Client ← Response ← Server
```

---

## 25. What is a port?

A port identifies a logical service/process endpoint on a host.

Common ports:

| Service | Port |
|---|---:|
| HTTP | 80 |
| HTTPS | 443 |
| SSH | 22 |
| DNS | 53 |
| PostgreSQL | 5432 |
| MySQL | 3306 |

### Real-life analogy

IP address = apartment building address.

Port = apartment number.

```text
192.168.1.10:3000
       IP   Port
```

---

## 26. What is localhost?

`localhost` means the local machine.

Common IPv4 loopback address:

```text
127.0.0.1
```

Example:

```text
http://localhost:3000
```

means:

```text
This computer → port 3000
```

---

## 27. What is loopback?

Loopback allows a machine to communicate with itself.

IPv4:

```text
127.0.0.1
```

IPv6:

```text
::1
```

Example:

```text
Browser
   |
127.0.0.1
   |
Local Node.js server
```

---

## 28. What is a private IP address?

Private IPv4 ranges are used inside private networks.

```text
10.0.0.0/8
172.16.0.0/12
192.168.0.0/16
```

Example:

```text
Laptop → 192.168.1.20
Router → 192.168.1.1
```

These addresses are not directly routable on the public Internet.

---

## 29. What is a public IP?

A public IP is globally routable on the Internet.

Example:

```text
Client
192.168.1.20
     |
     | NAT
     ↓
Public IP
203.0.113.x
     |
 Internet
```

---

## 30. What is a default gateway?

The default gateway is the router a host uses when the destination is outside its local subnet.

Example:

```text
Laptop
192.168.1.20
     |
     | Default gateway
     ↓
192.168.1.1
     |
 Internet
```

### Key Point

> Destination outside my network? Send it to the default gateway.

---

# 2. OSI & TCP/IP — 31–55

## 31. What is the OSI model?

OSI = **Open Systems Interconnection**.

It has seven layers:

```text
7  Application
6  Presentation
5  Session
4  Transport
3  Network
2  Data Link
1  Physical
```

Mnemonic:

> **All People Seem To Need Data Processing**

---

## 32. What is the Physical layer?

Layer 1 transmits raw bits.

Examples:

- Ethernet cable
- Fiber
- Radio
- Electrical signals

```text
101101001010
↓↓↓↓↓↓↓↓↓↓↓↓
Physical medium
```

---

## 33. What is the Data Link layer?

Layer 2 handles local network delivery.

Important concepts:

- MAC address
- Ethernet
- Frames
- VLAN

```text
PC A -- Ethernet Frame --> Switch --> PC B
```

---

## 34. What is the Network layer?

Layer 3 handles logical addressing and routing.

Important protocol:

```text
IP
```

Example:

```text
192.168.1.10 → 8.8.8.8
```

A router operates primarily here.

---

## 35. What is the Transport layer?

Layer 4 provides transport between applications.

Main protocols:

```text
TCP
UDP
```

---

## 36. What is the Session layer?

Layer 5 deals with managing communication sessions.

In modern TCP/IP implementations, many OSI session responsibilities are handled by application protocols/libraries rather than a distinct session-layer protocol.

---

## 37. What is the Presentation layer?

Layer 6 concerns representation of data, including concepts such as:

- Encoding
- Compression
- Encryption

Modern Internet stacks do not always implement this as a separate layer.

---

## 38. What is the Application layer?

Layer 7 provides network services to applications.

Examples:

```text
HTTP
DNS
SMTP
FTP
SSH
```

---

## 39. What is the TCP/IP model?

A common four-layer representation is:

```text
Application
Transport
Internet
Network Access
```

Mapping:

```text
OSI                    TCP/IP

Application  ┐
Presentation ├──────→ Application
Session      ┘

Transport ───────────→ Transport

Network ─────────────→ Internet

Data Link ┐
Physical  ┴──────────→ Network Access
```

---

## 40. OSI vs TCP/IP

| OSI | TCP/IP |
|---|---|
| 7 layers | Commonly 4 layers |
| Reference model | Practical protocol architecture |
| Separates session/presentation | Combines them into application |

---

## 41. At which layer does TCP operate?

TCP operates at:

```text
Layer 4 — Transport
```

---

## 42. At which layer does IP operate?

IP operates at:

```text
Layer 3 — Network
```

---

## 43. At which layer does Ethernet operate?

Ethernet is primarily a Layer 2 technology, with physical specifications also covering Layer 1.

---

## 44. At which layer does HTTP operate?

HTTP is an application-layer protocol.

```text
Application → HTTP
Transport   → TCP/QUIC
Internet    → IP
```

---

## 45. What is encapsulation?

As data moves down the stack, each layer adds control information.

```text
Application
    ↓
   Data
    ↓
TCP Segment
    ↓
IP Packet
    ↓
Ethernet Frame
    ↓
Bits
```

### Real-life analogy

Think of mailing a letter:

```text
Message
  ↓
Envelope
  ↓
Box
  ↓
Delivery truck
```

Each layer adds information needed by the next stage.

---

## 46. What is decapsulation?

The receiver removes the headers as the data moves upward.

```text
Bits
 ↓
Frame
 ↓
Packet
 ↓
Segment
 ↓
Application Data
```

---

## 47. What is a TCP segment?

A TCP segment is the transport-layer data unit used by TCP.

```text
TCP Header + Application Data
```

---

## 48. What is a datagram?

"Datagram" is commonly used for a UDP data unit and can also describe an independently routed IP packet depending on context.

---

## 49. What is a PDU?

PDU = **Protocol Data Unit**.

Typical terminology:

```text
Application → Data
TCP         → Segment
UDP         → Datagram
IP          → Packet
Ethernet    → Frame
Physical    → Bits
```

---

## 50. What is multiplexing?

Multiplexing allows many applications to share the same host/network connection using transport-layer ports.

Example:

```text
Browser → 443
SSH     → 22
Database→ 5432
```

Same machine, different ports.

---

## 51. What is demultiplexing?

The receiver uses destination information such as port numbers to deliver incoming transport data to the correct application/socket.

```text
Incoming packet
      |
      +---- Port 443 → Web application
      |
      +---- Port 22  → SSH
```

---

## 52. What is end-to-end communication?

It describes communication between endpoints/applications across the network.

```text
Client Application
       |
       | Network
       |
Server Application
```

---

## 53. What is peer-to-peer networking?

In P2P networking, devices can act as both clients and servers.

```text
Peer A ↔ Peer B
  ↕         ↕
Peer C ↔ Peer D
```

---

## 54. What is client-server architecture?

```text
Client
  |
  | Request
  ↓
Server
  |
  | Response
  ↓
Client
```

Example:

```text
Next.js frontend → Express API → PostgreSQL
```

---

## 55. Why is the OSI model useful?

It helps developers and network engineers isolate problems.

Example:

```text
No Wi-Fi signal?
→ Physical/Data Link problem

Can reach IP but DNS fails?
→ DNS/Application problem

Port unreachable?
→ Transport/firewall/service problem
```

### Interview Key Point

> OSI is mainly a conceptual troubleshooting and communication model.

---

# 3. TCP, UDP & Transport — 56–85

## 56. What is TCP?

TCP = **Transmission Control Protocol**.

TCP provides:

- Reliable delivery
- Ordered byte stream
- Error detection
- Flow control
- Congestion control
- Connection-oriented communication

---

## 57. What is UDP?

UDP = **User Datagram Protocol**.

UDP is:

- Connectionless
- Lightweight
- Low overhead
- No guarantee of delivery
- No guarantee of ordering

---

## 58. TCP vs UDP

| TCP | UDP |
|---|---|
| Connection-oriented | Connectionless |
| Reliable | No delivery guarantee |
| Ordered byte stream | Datagram-based |
| Flow control | No TCP-style flow control |
| Congestion control | No TCP-style congestion control |
| More overhead | Lower overhead |

---

## 59. When should you use UDP?

Examples:

```text
DNS
VoIP
Online games
Real-time media
QUIC
```

### Real-life example

In a live voice call, receiving a very old audio packet after a newer packet may be useless.

```text
Packet 1 → lost
Packet 2 → received
Packet 1 arrives late

Better to continue than wait forever.
```

---

## 60. When should you use TCP?

Use TCP when reliable, ordered delivery is important.

Examples:

```text
SSH
HTTP/1.1
HTTP/2
Database connections
File transfers
```

---

## 61. What is a TCP connection?

A TCP connection is a logical communication relationship between two endpoints.

It is identified using endpoint information such as:

```text
Source IP
Source Port
Destination IP
Destination Port
Protocol
```

---

## 62. Explain the TCP three-way handshake.

```text
Client                         Server

  | -------- SYN ------------> |
  |                            |
  | <------ SYN + ACK -------- |
  |                            |
  | -------- ACK ------------> |
  |                            |
  |      Connection ready      |
```

### Why?

It establishes connection state and synchronizes sequence numbers.

---

## 63. Why does TCP use a three-way handshake?

The handshake allows both sides to:

1. Confirm reachability.
2. Establish connection state.
3. Synchronize initial sequence numbers.

### Interview answer

> TCP uses three messages so both endpoints can establish synchronized connection state and confirm that communication is possible in both directions.

---

## 64. What is SYN?

SYN is a TCP flag used to initiate a connection and synchronize sequence numbers.

---

## 65. What is ACK?

ACK indicates acknowledgment of received data or connection-related information.

---

## 66. What is FIN?

FIN indicates that an endpoint has finished sending data in that direction and wants to close its sending side.

---

## 67. What is RST?

RST = **Reset**.

It immediately aborts/rejects a TCP connection in situations where continuing the connection is not appropriate.

Example:

```text
Client → Server: SYN
Server → Client: RST
```

Possible reason: no service is listening on that port.

---

## 68. How does TCP terminate a connection?

A typical graceful close:

```text
Client                         Server

  | -------- FIN ------------> |
  | <-------- ACK ------------ |
  | <-------- FIN ------------ |
  | -------- ACK ------------> |
```

Why four messages?

Each direction of a TCP connection closes independently.

---

## 69. What is a TCP sequence number?

It identifies the position of bytes in the TCP byte stream.

Example:

```text
Bytes:
1000 1001 1002 1003 ...
```

Sequence numbers allow TCP to track data ordering and retransmission.

---

## 70. What is a TCP acknowledgment number?

The acknowledgment number indicates the next byte the receiver expects.

Example:

```text
Received bytes: 1000–1999
ACK = 2000
```

Meaning:

> I have received everything before byte 2000 and expect byte 2000 next.

---

## 71. What is TCP flow control?

Flow control prevents a sender from overwhelming the receiver.

```text
Fast Sender
    |
    | too much data
    ↓
Slow Receiver
```

TCP uses a receive window to communicate how much data the receiver can accept.

---

## 72. What is TCP congestion control?

Congestion control tries to prevent the network itself from becoming overloaded.

```text
Sender
  |
  | too much traffic
  ↓
Network congestion
  |
  ↓
Packet loss / delay
```

Important concepts:

- Slow start
- Congestion avoidance
- Fast retransmit
- Fast recovery

---

## 73. Flow control vs congestion control

### Flow control

Protects the **receiver**.

```text
Sender → Receiver
```

### Congestion control

Protects the **network**.

```text
Sender → Network → Receiver
```

### Memory trick

> Flow = receiver capacity  
> Congestion = network capacity

---

## 74. What is a TCP window?

A TCP window represents how much data can be in flight without requiring an acknowledgment before more can be sent, subject to TCP's congestion and receive-window rules.

---

## 75. What is sliding window?

The sliding window allows multiple bytes/segments to be in flight.

```text
Sent:
[1][2][3][4][5]

ACK received for 1,2

Window moves:

      [3][4][5][6][7]
```

This improves network utilization compared with sending one segment and waiting for each ACK.

---

## 76. What is retransmission?

Retransmission means sending data again when TCP determines that previous data was lost or not properly acknowledged.

```text
Sender → Packet 1 → X lost
Sender → Packet 1 again
```

---

## 77. What is packet loss?

Packet loss occurs when packets fail to reach their destination.

Possible causes:

- Congestion
- Bad cable
- Wireless interference
- Hardware problems
- Routing problems
- Queue overflow

---

## 78. What is jitter?

Jitter is variation in packet arrival time.

Example:

```text
Packet 1 → 20 ms
Packet 2 → 21 ms
Packet 3 → 80 ms
Packet 4 → 25 ms
```

Packet 3 introduces significant variation.

Important for:

- Voice calls
- Video calls
- Gaming

---

## 79. What is RTT?

RTT = **Round-Trip Time**.

```text
Client -------- Request --------> Server
Client <------- Response -------- Server
                 ↑
              RTT
```

If:

```text
ping = 30 ms
```

the measured round-trip time is around 30 ms for that probe.

---

## 80. What is MSS?

MSS = **Maximum Segment Size**.

It is the maximum TCP payload size a host advertises for received TCP segments.

Typical IPv4 Ethernet example:

```text
MTU = 1500
IPv4 header = 20
TCP header = 20

MSS ≈ 1460
```

---

## 81. What is MTU?

MTU = **Maximum Transmission Unit**.

It is the maximum IP packet size a link can carry without fragmentation at that link.

Typical Ethernet:

```text
MTU = 1500 bytes
```

---

## 82. MSS vs MTU

```text
        Ethernet Frame
+-----------------------------+
| Ethernet | IP | TCP | Data |
+-----------------------------+
            <-------->
               MTU
```

For a common IPv4/TCP Ethernet path:

```text
MTU = 1500
IP header = 20
TCP header = 20
MSS = 1460
```

### Key Point

> MTU concerns the packet/link limit; MSS concerns TCP payload size.

---

## 83. What is a socket?

A socket is a software endpoint for network communication.

Example:

```text
192.168.1.20:5000
```

A server may listen on:

```text
0.0.0.0:3000
```

meaning port 3000 on all local IPv4 interfaces.

---

## 84. What is an ephemeral port?

An ephemeral port is a temporary port selected by the operating system, commonly for the client side of outgoing connections.

Example:

```text
Client: 192.168.1.20:51732
Server: 93.184.216.34:443
```

`51732` is an example of an ephemeral client port.

---

## 85. What is port scanning?

Port scanning checks which ports on a host are reachable/open.

Example:

```bash
nmap example.com
```

### Real-life analogy

Imagine checking an apartment building to see which doors respond.

### Security note

Only scan systems you own or have permission to test.

---

# 4. IP Addressing & Subnetting — 86–110

## 86. What is subnetting?

Subnetting divides a larger IP network into smaller networks.

Example:

```text
192.168.1.0/24
       |
       +---- /26
       |       |
       |       +---- Subnet 1
       |       +---- Subnet 2
       |       +---- Subnet 3
       |       +---- Subnet 4
```

Benefits:

- Better address management
- Smaller broadcast domains
- Network organization
- Segmentation

---

## 87. What is a subnet mask?

A subnet mask determines which bits belong to the network and which belong to hosts.

Example:

```text
IP:   192.168.1.25
Mask: 255.255.255.0
```

CIDR:

```text
192.168.1.25/24
```

---

## 88. What is CIDR?

CIDR = **Classless Inter-Domain Routing**.

Example:

```text
192.168.1.0/24
```

`/24` means:

```text
24 network-prefix bits
8 host bits
```

---

## 89. How many addresses are in /24?

IPv4 has 32 bits.

```text
Host bits = 32 - 24
          = 8

Addresses = 2^8
          = 256
```

Traditional usable hosts:

```text
256 - 2 = 254
```

The two traditionally reserved addresses are:

```text
Network address
Broadcast address
```

---

## 90. How many addresses are in /16?

```text
Host bits = 32 - 16 = 16

2^16 = 65,536 addresses
```

Traditional usable:

```text
65,534
```

---

## 91. How many addresses are in /30?

```text
Host bits = 32 - 30 = 2

2^2 = 4 addresses
```

Traditional usable:

```text
2
```

Common historical use:

```text
Router A ←→ Router B
```

---

## 92. What is a network address?

The network address identifies the subnet.

Example:

```text
192.168.1.0/24
```

Network:

```text
192.168.1.0
```

Hosts traditionally start at:

```text
192.168.1.1
```

---

## 93. What is a broadcast address?

The IPv4 broadcast address targets all hosts in a subnet.

For:

```text
192.168.1.0/24
```

broadcast:

```text
192.168.1.255
```

---

## 94. What is a host address?

A host address identifies an individual interface inside an IPv4 subnet.

Example:

```text
192.168.1.25
```

inside:

```text
192.168.1.0/24
```

---

## 95. Subnetting vs supernetting

### Subnetting

```text
Large network
     ↓
Smaller networks
```

### Supernetting / route aggregation

```text
Several networks
     ↓
One summarized route
```

Route aggregation helps reduce routing table size.

---

## 96. What is route aggregation?

Route aggregation combines multiple routes into a summarized route.

Example concept:

```text
10.0.0.0/24
10.0.1.0/24
10.0.2.0/24
10.0.3.0/24
       ↓
Summarized route
10.0.0.0/22
```

---

## 97. What is a subnet prefix?

The subnet prefix is the network portion represented by the CIDR length.

Example:

```text
192.168.10.0/24
```

Prefix length:

```text
24 bits
```

---

## 98. What is a default route?

A default route is used when no more specific route matches.

IPv4:

```text
0.0.0.0/0
```

IPv6:

```text
::/0
```

Example:

```text
Destination unknown
       ↓
Use default route
       ↓
Internet gateway
```

---

## 99. What is a routing table?

A routing table tells a host/router where to send packets.

Example:

```text
Destination       Gateway        Interface
192.168.1.0/24    connected      eth0
10.0.0.0/8        192.168.1.1    eth0
0.0.0.0/0         192.168.1.1    eth0
```

---

## 100. What is a next hop?

The next hop is the next router/device that receives a packet on its way toward the destination.

```text
PC → Router A → Router B → Server
       ↑
    next hop
```

---

## 101. What is ARP?

ARP = **Address Resolution Protocol**.

It maps an IPv4 address to a MAC address on a local network.

Example:

```text
PC wants:
192.168.1.1

ARP:
"Who has 192.168.1.1?"

Router:
"192.168.1.1 is at AA:BB:CC:DD:EE:FF"
```

---

## 102. What is an ARP cache?

An ARP cache stores recently learned IP-to-MAC mappings.

Linux:

```bash
ip neigh
```

Example:

```text
192.168.1.1 dev wlan0 lladdr aa:bb:cc:dd:ee:ff REACHABLE
```

---

## 103. What is NDP?

NDP = **Neighbor Discovery Protocol**.

It is used by IPv6 and is implemented using ICMPv6.

It handles functions such as:

- Neighbor discovery
- Address resolution
- Router discovery
- Duplicate address detection

---

## 104. What is NAT?

NAT = **Network Address Translation**.

It translates addresses between networks/address spaces.

Typical home network:

```text
Laptop 192.168.1.20
       |
Phone  192.168.1.21
       |
       +---- Router/NAT ---- Public IP ---- Internet
```

---

## 105. Why is NAT used?

Common reasons:

- IPv4 address conservation
- Private internal addressing
- Network design flexibility

---

## 106. What is PAT?

PAT = **Port Address Translation**.

Multiple private devices share one public IPv4 address using different ports.

```text
192.168.1.20:5000
          \
           NAT → PublicIP:40001
          /
192.168.1.21:5000
          \
           NAT → PublicIP:40002
```

---

## 107. What is DHCP?

DHCP = **Dynamic Host Configuration Protocol**.

It can provide:

- IP address
- Network prefix/subnet mask
- Default gateway
- DNS servers
- Other configuration

---

## 108. What is DHCP DORA?

DORA:

```text
Client                     DHCP Server

  | ---- Discover -------> |
  | <----- Offer --------- |
  | ---- Request --------> |
  | <--- Acknowledge ----- |
```

### Memory trick

> **D**iscover → **O**ffer → **R**equest → **A**cknowledge

---

## 109. What is APIPA?

APIPA is automatic IPv4 link-local addressing used when a DHCP client cannot obtain an address.

Range:

```text
169.254.0.0/16
```

If your computer gets:

```text
169.254.x.x
```

one possible explanation is DHCP failure.

---

## 110. What is a VLAN?

VLAN = **Virtual Local Area Network**.

It logically separates Layer 2 broadcast domains.

Example:

```text
             Switch
          /          \
     VLAN 10        VLAN 20
      Staff          Guest
       |               |
     PCs             Phones
```

Even if devices share one physical switch, VLANs can separate them logically.

---

# 5. DNS, HTTP & Web Networking — 111–130

## 111. What is DNS?

DNS = **Domain Name System**.

It translates names into IP information and supports many other DNS records.

```text
example.com
     ↓
DNS
     ↓
93.184.216.34
```

### Real-life analogy

DNS is the Internet's contact directory.

---

## 112. Why do we need DNS?

Humans prefer names:

```text
google.com
```

rather than remembering numeric IP addresses.

Applications also benefit because DNS names can remain stable while IP infrastructure changes.

---

## 113. What is DNS resolution?

DNS resolution is the process of obtaining DNS information for a domain name.

Simplified:

```text
Browser
   |
   ↓
Resolver
   |
   ↓
DNS hierarchy
   |
   ↓
Answer
```

---

## 114. What is a DNS resolver?

A DNS resolver obtains DNS answers for clients.

It may:

- Check its cache
- Query recursive DNS servers
- Contact authoritative DNS servers

---

## 115. What is an authoritative DNS server?

An authoritative DNS server stores and serves the authoritative DNS records for a zone.

Example concept:

```text
example.com
     |
Authoritative DNS
     |
A → 93.184.216.34
```

---

## 116. What is an A record?

An A record maps a hostname to an IPv4 address.

```text
example.com → 93.184.216.34
```

---

## 117. What is an AAAA record?

An AAAA record maps a hostname to an IPv6 address.

```text
example.com → 2001:db8::10
```

---

## 118. What is a CNAME?

CNAME creates an alias from one DNS name to another.

Example:

```text
www.example.com
      ↓ CNAME
example.com
```

---

## 119. What is an MX record?

MX = **Mail Exchange**.

It specifies mail servers responsible for receiving email for a domain.

```text
example.com
     |
     +--- MX → mail.example.com
```

---

## 120. What is DNS caching?

DNS caching stores DNS answers temporarily.

```text
First request:
Browser → Resolver → DNS hierarchy

Later request:
Browser → Cache → Answer
```

This reduces latency and DNS traffic.

---

## 121. What is DNS TTL?

TTL = **Time To Live**.

It indicates how long a DNS response can generally be cached.

Example:

```text
TTL = 300 seconds
```

A resolver may cache the answer for approximately five minutes.

---

## 122. What is HTTP?

HTTP = **Hypertext Transfer Protocol**.

It is an application-layer request/response protocol.

```text
Browser → HTTP Request → Server
Browser ← HTTP Response ← Server
```

---

## 123. What is HTTPS?

HTTPS is HTTP protected using TLS.

```text
HTTP
 +
TLS
 ↓
HTTPS
```

Usually:

```text
HTTP  → 80
HTTPS → 443
```

---

## 124. HTTP vs HTTPS

### HTTP

```text
Client ---- HTTP ----> Server
```

Traffic is not protected by TLS.

### HTTPS

```text
Client ==== TLS + HTTP ==== Server
```

TLS provides encryption, integrity protection, and server authentication.

---

## 125. What is TLS?

TLS = **Transport Layer Security**.

It provides:

- Encryption
- Integrity
- Authentication

### Real-life analogy

HTTP is like sending a postcard.

HTTPS/TLS is like putting the message inside a secure envelope.

---

## 126. What happens when you enter `https://example.com`?

A simplified flow:

```text
1. Browser parses URL
          ↓
2. Browser checks local/cache information
          ↓
3. DNS resolution
          ↓
4. Connection establishment
          ↓
5. TLS handshake
          ↓
6. HTTP request
          ↓
7. Server/load balancer/backend
          ↓
8. HTTP response
          ↓
9. Browser downloads required resources
          ↓
10. Browser renders page
```

Modern systems may reuse connections and caches, so the exact sequence can differ.

---

## 127. What is an HTTP request?

An HTTP request contains information such as:

```http
GET /users HTTP/1.1
Host: example.com
Accept: application/json
```

It can contain:

- Method
- URL/path
- Headers
- Body

---

## 128. What is an HTTP response?

Example:

```http
HTTP/1.1 200 OK
Content-Type: application/json

{"name":"Imtius"}
```

A response contains:

- Status code
- Headers
- Optional body

---

## 129. What are HTTP methods?

### GET

Retrieve data.

```http
GET /users
```

### POST

Create/process data.

```http
POST /users
```

### PUT

Replace a resource representation.

```http
PUT /users/10
```

### PATCH

Partially update a resource.

```http
PATCH /users/10
```

### DELETE

Delete a resource.

```http
DELETE /users/10
```

### HEAD

Similar to GET but without a response body.

### OPTIONS

Used to discover supported methods/capabilities and is important in CORS preflight.

---

## 130. What are common HTTP status codes?

### Success

```text
200 OK
201 Created
204 No Content
```

### Redirection

```text
301 Moved Permanently
302 Found
304 Not Modified
```

### Client errors

```text
400 Bad Request
401 Unauthorized
403 Forbidden
404 Not Found
409 Conflict
429 Too Many Requests
```

### Server errors

```text
500 Internal Server Error
502 Bad Gateway
503 Service Unavailable
504 Gateway Timeout
```

### Important interview distinction

```text
401 → authentication is required/failed
403 → server understood the request but refuses access
```

---

# 6. Mid/Hard Networking — 131–150

## 131. What is a proxy server?

A proxy is an intermediary between a client and another server.

```text
Client → Proxy → Server
```

### Real-life example

A company may configure employee computers to access the Internet through a proxy.

The proxy can:

- Filter traffic
- Cache content
- Apply policies
- Log requests

---

## 132. Forward proxy vs reverse proxy

### Forward proxy

Represents the **client**.

```text
Employee
   ↓
Forward Proxy
   ↓
Internet
```

### Reverse proxy

Represents the **server infrastructure**.

```text
Internet
   ↓
Reverse Proxy
   ↓
+---------+---------+
| Backend | Backend |
| Server  | Server  |
+---------+---------+
```

Examples:

- Nginx
- HAProxy
- Cloudflare

---

## 133. What is a load balancer?

A load balancer distributes incoming traffic across multiple backend servers.

```text
                  +--> Server A
Client → LB ------+--> Server B
                  +--> Server C
```

### Real-life analogy

Imagine a restaurant with three counters.

A receptionist directs customers to available counters instead of sending everyone to one counter.

---

## 134. What is health checking?

A load balancer checks whether backend servers are healthy.

Example:

```http
GET /health
```

Possible response:

```text
200 OK
```

If Server B stops responding:

```text
Client → Load Balancer
                 |
        +--------+--------+
        ↓        ↓        ↓
       A        B        C
      UP       DOWN      UP
```

Traffic is sent to A and C.

---

## 135. What is round-robin load balancing?

Requests are distributed sequentially.

```text
Request 1 → A
Request 2 → B
Request 3 → C
Request 4 → A
Request 5 → B
```

Simple and useful, but it does not necessarily account for server capacity or current load.

---

## 136. What is a sticky session?

Sticky sessions try to keep a client's requests on the same backend server.

```text
User A → Server 1
User A → Server 1
User A → Server 1
```

### Problem

If Server 1 fails, session continuity can become complicated.

Modern systems often prefer storing session state in shared infrastructure such as Redis or a database rather than relying heavily on local server memory.

---

## 137. What is a CDN?

CDN = **Content Delivery Network**.

It caches/distributes content through geographically distributed edge locations.

```text
User in Bangladesh
       |
       ↓
Nearest CDN Edge
       |
       ↓
Origin Server
```

### Example

Instead of downloading an image from a server far away every time, the image may be served from a nearby CDN edge.

Benefits:

- Lower latency
- Faster static content
- Reduced origin load

---

## 138. What is WebSocket?

WebSocket provides a persistent, bidirectional communication channel.

```text
Client ←────────────→ Server
       persistent
       connection
```

Useful for:

- Chat
- Live notifications
- Trading dashboards
- Multiplayer games
- Real-time monitoring

### Example

A chat application:

```text
Alice ───── WebSocket ───── Server
                              |
                              ↓
                           Bob's app
```

The server can push a message to Bob without waiting for Bob to make a new HTTP request.

---

## 139. HTTP polling vs WebSocket

### Polling

```text
Client → "Any new message?"
Server → "No"

Client → "Any new message?"
Server → "No"

Client → "Any new message?"
Server → "Yes!"
```

Many unnecessary requests can occur.

### WebSocket

```text
Client ═════════════ Server
          |
          | New message
          ↓
        Client
```

The server can push data immediately.

---

## 140. What is a firewall?

A firewall controls network traffic according to security rules.

Example:

```text
Internet
   |
Firewall
   |
Private Network
```

Rules may consider:

- Source IP
- Destination IP
- Port
- Protocol
- Connection state
- Application information

---

## 141. Stateful vs stateless firewall

### Stateless

Each packet is evaluated independently.

### Stateful

The firewall tracks connection state.

Example:

```text
Client → Server
SYN
   ↓
Firewall records connection

Server → Client
SYN-ACK
   ↓
Firewall knows it belongs to an existing flow
```

### Key Point

> Stateful firewall = understands connection state.

---

## 142. What is ICMP?

ICMP = **Internet Control Message Protocol**.

It supports network diagnostics and control/error messages.

Examples:

```text
ping
traceroute
```

---

## 143. What is ping?

`ping` commonly uses ICMP Echo Request and Echo Reply.

```text
Client ---- Echo Request ----> Server
Client <--- Echo Reply ------- Server
```

Example:

```bash
ping 8.8.8.8
```

It can help test reachability and measure RTT.

### Important

Ping failure does **not** always mean the host is down. Firewalls may block ICMP.

---

## 144. What is traceroute?

Traceroute helps identify the path toward a destination.

Linux:

```bash
traceroute google.com
```

or:

```bash
tracepath google.com
```

Simplified:

```text
Your PC
  ↓
Router 1
  ↓
ISP Router
  ↓
Router 3
  ↓
Google
```

It uses TTL/hop-limit behavior and responses from intermediate devices.

---

## 145. What is nslookup?

`nslookup` queries DNS.

```bash
nslookup google.com
```

Example purpose:

```text
Domain → IP
```

For more detailed DNS diagnostics:

```bash
dig google.com
```

---

## 146. Explain what happens when a packet travels from one network to another.

Suppose:

```text
PC A
192.168.1.10
    |
    ↓
Router
    |
    ↓
Internet
    |
    ↓
Server
203.0.113.10
```

### Step 1 — Destination check

The PC checks whether the destination is local.

```text
Source:      192.168.1.10
Destination: 203.0.113.10
```

The destination is not in the local subnet.

### Step 2 — Default gateway

The PC sends the packet to its router.

It first needs the router's MAC address if it is not already known, typically using ARP for IPv4.

### Step 3 — Router receives frame

```text
Ethernet frame
      ↓
Router
```

The router removes the incoming Layer 2 framing and examines the IP packet.

### Step 4 — Routing lookup

The router checks:

```text
Destination IP
       ↓
Routing table
       ↓
Best matching route
```

### Step 5 — Forwarding

The router decrements the IPv4 TTL and sends the packet through the selected interface.

A new Layer 2 frame is created for the next link.

### Important interview point

> MAC addresses normally change hop-by-hop, while the IP destination remains the same end-to-end unless a mechanism such as NAT changes it.

---

## 147. Explain the TCP three-way handshake deeply.

```text
Client                              Server

  |                                   |
  | -------- SYN, Seq=x ------------> |
  |                                   |
  | <--- SYN+ACK, Seq=y, Ack=x+1 ---- |
  |                                   |
  | -------- ACK, Ack=y+1 ----------> |
  |                                   |
  |          Connection ready         |
```

### Step 1 — SYN

Client says:

> I want to establish a TCP connection.

It sends an initial sequence number.

### Step 2 — SYN + ACK

Server says:

> I received your request, and I also want to establish communication.

It sends its own sequence number and acknowledges the client's SYN.

### Step 3 — ACK

Client acknowledges the server's SYN.

Now both sides have synchronized TCP state.

### Interview Key Point

Do not simply say:

> "Three-way handshake makes TCP reliable."

Better answer:

> It establishes connection state and synchronizes sequence numbers while confirming that both endpoints can communicate.

---

## 148. What happens when you type a URL into a browser?

Example:

```text
https://api.example.com/users
```

### Full simplified flow

```text
              Browser
                 |
                 | 1. Parse URL
                 ↓
          Cache / Local checks
                 |
                 | 2. DNS
                 ↓
          DNS Resolver
                 |
                 | IP address
                 ↓
        Connection establishment
                 |
                 ↓
            TLS handshake
                 |
                 ↓
           HTTP request
                 |
                 ↓
       CDN / Load Balancer
                 |
                 ↓
         Reverse Proxy
                 |
                 ↓
          Backend Server
                 |
                 ↓
            Database
                 |
                 ↓
         HTTP Response
                 |
                 ↓
              Browser
```

### Example request

```http
GET /users HTTP/1.1
Host: api.example.com
Authorization: Bearer <token>
```

### Example response

```http
HTTP/1.1 200 OK
Content-Type: application/json

[
  {"id":1,"name":"Imtius"}
]
```

### Important modern detail

HTTP versions use different transports:

```text
HTTP/1.1 → TCP
HTTP/2   → TCP
HTTP/3   → QUIC → UDP
```

---

## 149. TCP vs QUIC — why does HTTP/3 use QUIC?

TCP provides:

- Reliable delivery
- Ordered byte stream
- Congestion control

But HTTP/2 multiplexes many streams over one TCP connection. If TCP loses a packet, TCP's ordered byte stream can make delivery of later bytes wait for the missing data.

QUIC addresses this differently.

```text
HTTP/3
   ↓
 QUIC
   ↓
 UDP
   ↓
 IP
```

QUIC provides:

- Reliable delivery
- Multiple independent streams
- Integrated TLS 1.3
- Congestion control
- Connection migration
- Faster connection establishment in many situations

### Real-life analogy

Imagine one truck carrying packages for five customers.

With a single ordered delivery line, one missing package can delay later packages.

QUIC has independent streams so loss affecting one stream does not necessarily block delivery of unrelated streams at the application level.

### Interview Key Point

> HTTP/3 uses QUIC over UDP. QUIC provides transport reliability, congestion control, TLS integration, multiplexed streams, and connection migration without relying on TCP.

---

## 150. A server is reachable by IP but not by domain name. How do you troubleshoot?

This is an excellent real-world interview question.

### Situation

```text
curl http://203.0.113.10
      ↓
Works

curl http://example.com
      ↓
Fails
```

This strongly suggests investigating DNS and then hostname-dependent layers.

### Step 1 — Test DNS

```bash
nslookup example.com
```

or:

```bash
dig example.com
```

If DNS does not return the expected address, investigate:

- A record
- AAAA record
- CNAME
- DNS server
- DNS cache
- DNS propagation/TTL

### Step 2 — Test the returned IP

```bash
ping 203.0.113.10
```

or:

```bash
curl -v http://203.0.113.10
```

### Step 3 — Test the hostname with curl

```bash
curl -v https://example.com
```

### Step 4 — Check the port

```bash
nc -vz example.com 443
```

### Step 5 — Check TLS

For HTTPS:

```bash
openssl s_client -connect example.com:443 -servername example.com
```

The `-servername` option is important because many servers use SNI to select the correct certificate/site.

### Step 6 — Check reverse proxy/load balancer

Example:

```text
Internet
   |
Nginx / Cloudflare
   |
Backend
```

The server may behave differently depending on the requested hostname.

### Troubleshooting model

```text
DNS
 ↓
IP connectivity
 ↓
Port
 ↓
TLS
 ↓
HTTP
 ↓
Application
```

### Interview Key Point

> Troubleshoot layer by layer instead of randomly changing configuration.

---

# ⭐ 20 Questions to Memorize First

If you have limited time, prioritize these:

1. What is IP?
2. IP vs MAC
3. TCP vs UDP
4. TCP three-way handshake
5. TCP connection termination
6. OSI model
7. TCP/IP model
8. HTTP vs HTTPS
9. HTTP methods
10. HTTP status codes
11. DNS
12. DNS resolution
13. DHCP/DORA
14. NAT/PAT
15. ARP
16. Router vs switch
17. CIDR/subnetting
18. Default gateway
19. Reverse proxy/load balancer
20. What happens when you enter a URL?

---

# 🔥 Hard Topics to Master for Software Engineer Interviews

For a backend/full-stack role, make sure you can explain these without memorizing word-for-word:

- TCP handshake
- TCP termination
- Sequence numbers
- ACK numbers
- Flow control
- Congestion control
- Sliding window
- Retransmission
- Packet loss
- RTT
- MTU vs MSS
- IPv4 subnetting
- CIDR
- ARP
- NDP
- NAT/PAT
- DNS recursive vs authoritative
- DNS caching/TTL
- Reverse proxy
- Load balancing
- Health checks
- WebSocket
- TLS
- HTTP/1.1 vs HTTP/2 vs HTTP/3
- TCP vs QUIC
- Network troubleshooting

---

# 🧪 Practical Linux Networking Commands

These are very useful for Linux-based developer interviews.

## 1. Check IP addresses

```bash
ip addr
```

Short form:

```bash
ip a
```

Example:

```text
wlan0:
    inet 192.168.1.20/24
```

---

## 2. Check routing table

```bash
ip route
```

Example:

```text
default via 192.168.1.1 dev wlan0
192.168.1.0/24 dev wlan0
```

Meaning:

```text
Unknown destination
       ↓
192.168.1.1
```

---

## 3. Check neighbor/ARP information

```bash
ip neigh
```

Example:

```text
192.168.1.1 dev wlan0 lladdr aa:bb:cc:dd:ee:ff REACHABLE
```

---

## 4. Test connectivity

```bash
ping 8.8.8.8
```

Test a domain:

```bash
ping google.com
```

---

## 5. Check DNS

```bash
nslookup google.com
```

Better diagnostic tool:

```bash
dig google.com
```

---

## 6. Check HTTP

```bash
curl https://example.com
```

Detailed:

```bash
curl -v https://example.com
```

Headers only:

```bash
curl -I https://example.com
```

---

## 7. Check listening ports

```bash
ss -lntup
```

Useful for backend developers.

Example:

```text
LISTEN 0 511 0.0.0.0:3000
```

This can mean an application is listening on TCP port 3000 on all IPv4 interfaces.

---

## 8. Check a specific port

```bash
nc -vz localhost 3000
```

Example:

```text
Connection to localhost 3000 port [tcp/*] succeeded!
```

---

## 9. Trace network path

```bash
traceroute google.com
```

Alternative:

```bash
tracepath google.com
```

---

## 10. Inspect DNS in detail

```bash
dig example.com
```

A record:

```bash
dig example.com A
```

AAAA:

```bash
dig example.com AAAA
```

MX:

```bash
dig example.com MX
```

---

## 11. Inspect TLS

```bash
openssl s_client \
  -connect example.com:443 \
  -servername example.com
```

Useful for investigating certificates and TLS handshakes.

---

## 12. Capture packets

```bash
sudo tcpdump -i any
```

Filter TCP port 443:

```bash
sudo tcpdump -i any tcp port 443
```

Filter DNS:

```bash
sudo tcpdump -i any port 53
```

### Why is tcpdump useful?

It lets you see actual packets instead of guessing.

---

# 🧠 Real-Life Architecture Example

Imagine you build a Next.js + Node.js + PostgreSQL application.

```text
                         Internet
                            |
                            ↓
                     DNS: example.com
                            |
                            ↓
                         CDN/WAF
                            |
                            ↓
                    Load Balancer
                       /       \
                      /         \
                     ↓           ↓
                Next.js       Next.js
                Server 1      Server 2
                     \         /
                      \       /
                       ↓     ↓
                    Node/API
                        |
                        ↓
                    PostgreSQL
```

Now map networking concepts:

```text
DNS
 ↓
Find server IP

HTTPS
 ↓
Secure browser ↔ server communication

TLS
 ↓
Encryption/authentication

Load Balancer
 ↓
Distribute traffic

TCP/QUIC
 ↓
Transport communication

IP
 ↓
Routing

Router
 ↓
Connect networks

Port
 ↓
Identify services

Firewall
 ↓
Control access

PostgreSQL: 5432
Node API: e.g. 3000
HTTPS: 443
```

---

# 🎯 Backend Developer Example

Suppose your Node.js server runs:

```bash
npm run dev
```

and listens on:

```text
localhost:3000
```

You open:

```text
http://localhost:3000/api/users
```

The flow is:

```text
Browser
   |
   | HTTP
   ↓
127.0.0.1:3000
   |
   ↓
Node.js / Express
   |
   | SQL/TCP connection
   ↓
PostgreSQL
```

No Internet is required for the browser-to-server part because `localhost` means the local machine.

---

# 🎯 Real-Life Wi-Fi Example

You connect your laptop to home Wi-Fi.

### Step 1

Laptop searches for a Wi-Fi network.

```text
Laptop → Wi-Fi Router
```

### Step 2

DHCP gives the laptop an address.

```text
Laptop
192.168.1.20
```

### Step 3

Gateway:

```text
192.168.1.1
```

### Step 4

You open:

```text
https://google.com
```

### Step 5

DNS resolves the domain.

```text
google.com
    ↓
IP address
```

### Step 6

Your laptop sends traffic toward the default gateway.

### Step 7

The router performs NAT/PAT for Internet access.

### Step 8

Traffic crosses multiple routers.

### Step 9

Google's infrastructure receives the request.

### Step 10

The response travels back.

```text
Laptop
 ↓
Wi-Fi Router
 ↓
ISP
 ↓
Internet
 ↓
Google
 ↓
Internet
 ↓
ISP
 ↓
Router
 ↓
Laptop
```

---

# 🚨 Common Interview Traps

## Trap 1

### Question:
Is IP address the same as MAC address?

### Wrong:
> Yes, both identify the computer.

### Better:
> No. IP is a logical Layer 3 address used for routing, while MAC is a Layer 2 address used for local-link delivery.

---

## Trap 2

### Question:
Is TCP always faster than UDP?

### Answer:

No.

TCP provides reliability and ordering but adds protocol overhead and connection/state management.

UDP has lower protocol overhead but does not provide TCP's reliability and ordering.

---

## Trap 3

### Question:
Does HTTPS mean HTTP uses a different port?

Not exactly.

HTTPS is HTTP carried over TLS.

Typical ports:

```text
HTTP  → 80
HTTPS → 443
```

The security difference comes from TLS, not merely the port number.

---

## Trap 4

### Question:
Does ping prove a website is working?

No.

A host may respond to ICMP while its web server is down.

For example:

```text
ping example.com       → works
curl https://example.com → fails
```

The network host may be reachable while the application is unavailable.

---

## Trap 5

### Question:
Does a switch use IP addresses?

A normal Layer 2 switch primarily forwards Ethernet frames based on MAC addresses.

Layer 3 switches can also perform routing using IP.

---

## Trap 6

### Question:
Does DNS only convert domain names into IP addresses?

No.

DNS supports many record types:

```text
A
AAAA
CNAME
MX
TXT
NS
SOA
```

---

# 📌 Final Interview Cheat Sheet

```text
NETWORK
  |
  +-- LAN / WAN
  |
  +-- IP
  |    +-- IPv4
  |    +-- IPv6
  |
  +-- MAC
  |
  +-- Router
  |
  +-- Switch
  |
  +-- Port
  |
  +-- Protocol
       |
       +-- TCP
       +-- UDP
       +-- HTTP
       +-- HTTPS
       +-- DNS
       +-- DHCP
       +-- ARP
```

## OSI

```text
7 Application   → HTTP, DNS, SSH
6 Presentation  → Encoding/representation
5 Session        → Session management concepts
4 Transport     → TCP, UDP
3 Network       → IP, ICMP
2 Data Link     → Ethernet, MAC, VLAN
1 Physical      → Cable, radio, fiber
```

## TCP

```text
SYN
 ↓
SYN-ACK
 ↓
ACK
 ↓
DATA
 ↓
FIN
 ↓
ACK
 ↓
FIN
 ↓
ACK
```

## DNS

```text
Domain
  ↓
Resolver
  ↓
Cache?
  ↓
DNS hierarchy / authoritative server
  ↓
IP / DNS answer
```

## DHCP

```text
Discover
   ↓
Offer
   ↓
Request
   ↓
ACK
```

## HTTP

```text
Client
  |
  | Request
  ↓
Server
  |
  | Response
  ↓
Client
```

## Web application

```text
Browser
   ↓
DNS
   ↓
CDN/WAF
   ↓
Load Balancer
   ↓
Reverse Proxy
   ↓
Backend
   ↓
Database
```

---

# 🏆 7-Day Networking Study Plan

## Day 1 — Fundamentals

Study:

```text
1–30
```

Focus:

- IP
- MAC
- Router
- Switch
- Port
- LAN/WAN
- Bandwidth
- Latency

---

## Day 2 — OSI

Study:

```text
31–55
```

Memorize:

```text
Application
Presentation
Session
Transport
Network
Data Link
Physical
```

---

## Day 3 — TCP/UDP

Study:

```text
56–85
```

Focus heavily on:

- TCP handshake
- TCP termination
- Sequence numbers
- ACK
- Flow control
- Congestion control
- Sliding window
- MTU
- MSS

---

## Day 4 — IP/Subnetting

Study:

```text
86–110
```

Practice:

```text
/24
/25
/26
/27
/28
/30
```

---

## Day 5 — Web Networking

Study:

```text
111–130
```

Focus:

- DNS
- HTTP
- HTTPS
- TLS
- HTTP methods
- Status codes

---

## Day 6 — Hard Questions

Study:

```text
131–150
```

Especially:

```text
URL → Browser → DNS → TCP/QUIC → TLS → HTTP
```

---

## Day 7 — Practical

Run these commands:

```bash
ip a
ip route
ip neigh
ping google.com
nslookup google.com
dig google.com
curl -v https://google.com
ss -lntup
traceroute google.com
tracepath google.com
```

Then explain what each command does **without looking at the notes**.

---

# Final Rule for Interviews

When answering networking questions, use this structure:

```text
1. Definition
      ↓
2. How it works
      ↓
3. Real-life example
      ↓
4. Difference/comparison
      ↓
5. Key point
```

Example:

> **What is TCP?**
>
> TCP is a connection-oriented transport protocol that provides reliable, ordered delivery. It establishes a connection using a three-way handshake, uses acknowledgments and retransmissions for reliability, and provides flow and congestion control. For example, SSH commonly uses TCP because reliable ordered delivery is important.

That style sounds much stronger in a technical interview than giving only a one-line definition.
