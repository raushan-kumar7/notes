# TCS Digital Role - Computer Networks Interview Guide

## Network Fundamentals

### 1. What is a Computer Network?
**Answer:** A computer network is a collection of interconnected devices (computers, servers, routers, switches) that can communicate and share resources with each other. Networks enable data sharing, resource sharing, and communication between users.

**Key Components:**
- **Nodes:** Devices connected to the network (computers, servers, printers)
- **Links:** Physical or logical connections between nodes
- **Protocols:** Rules governing communication
- **Network Interface Cards (NICs):** Hardware for network connectivity
- **Network Operating System:** Software managing network resources

**Benefits:**
- Resource sharing (files, printers, internet)
- Communication (email, messaging, video calls)
- Centralized data management
- Cost reduction
- Improved reliability through redundancy

### 2. Types of Networks

#### Based on Geographic Coverage:

**Personal Area Network (PAN):**
- Range: Within 10 meters
- Examples: Bluetooth, USB connections
- Use case: Connecting personal devices

**Local Area Network (LAN):**
- Range: Within a building or campus (up to 1 km)
- Examples: Office networks, home Wi-Fi
- Characteristics: High speed, low latency, private ownership
- Technologies: Ethernet, Wi-Fi

**Metropolitan Area Network (MAN):**
- Range: Across a city (up to 50 km)
- Examples: Cable TV networks, city-wide Wi-Fi
- Technologies: Fiber optic, microwave

**Wide Area Network (WAN):**
- Range: Across countries/continents
- Examples: Internet, corporate networks
- Characteristics: Lower speed, higher latency, public/private
- Technologies: Leased lines, satellite, cellular

#### Based on Topology:

**Bus Topology:**
- All nodes connected to a single cable (bus)
- Advantages: Simple, cost-effective
- Disadvantages: Single point of failure, performance degrades with more nodes
- Example: Early Ethernet networks

**Star Topology:**
- All nodes connected to a central hub/switch
- Advantages: Easy to manage, no single point of failure for nodes
- Disadvantages: Central device failure affects entire network
- Example: Most modern LANs

**Ring Topology:**
- Nodes connected in a circular fashion
- Data travels in one direction
- Advantages: Equal access, no collisions
- Disadvantages: Single break affects entire network
- Example: Token Ring networks

**Mesh Topology:**
- Every node connected to every other node
- Types: Full mesh (all connected), Partial mesh (some connected)
- Advantages: High reliability, multiple paths
- Disadvantages: Expensive, complex
- Example: Internet backbone

**Hybrid Topology:**
- Combination of two or more topologies
- Example: Star-bus, star-ring combinations

## OSI Model

### 3. Seven Layers of OSI Model

**Layer 7 - Application Layer:**
- **Function:** Interface between user applications and network
- **Protocols:** HTTP/HTTPS, FTP, SMTP, DNS, DHCP
- **Examples:** Web browsers, email clients
- **Data Unit:** Data

**Layer 6 - Presentation Layer:**
- **Function:** Data translation, encryption, compression
- **Examples:** SSL/TLS, JPEG, MPEG, ASCII
- **Data Unit:** Data

**Layer 5 - Session Layer:**
- **Function:** Establishes, manages, terminates sessions
- **Examples:** NetBIOS, RPC, SQL sessions
- **Data Unit:** Data

**Layer 4 - Transport Layer:**
- **Function:** End-to-end delivery, error recovery, flow control
- **Protocols:** TCP, UDP
- **Data Unit:** Segments (TCP) / Datagrams (UDP)

**Layer 3 - Network Layer:**
- **Function:** Routing, logical addressing
- **Protocols:** IP, ICMP, OSPF, BGP
- **Devices:** Routers
- **Data Unit:** Packets

**Layer 2 - Data Link Layer:**
- **Function:** Frame formatting, error detection, MAC addressing
- **Protocols:** Ethernet, PPP, Wi-Fi
- **Devices:** Switches, Bridges
- **Data Unit:** Frames

**Layer 1 - Physical Layer:**
- **Function:** Physical transmission of raw bits
- **Examples:** Cables, hubs, repeaters, wireless signals
- **Data Unit:** Bits

### 4. TCP/IP Model vs OSI Model

| OSI Layer | TCP/IP Layer | Function | Protocols |
|-----------|--------------|----------|-----------|
| Application | Application | User interface | HTTP, FTP, SMTP |
| Presentation | Application | Data formatting | SSL, TLS |
| Session | Application | Session management | NetBIOS |
| Transport | Transport | End-to-end delivery | TCP, UDP |
| Network | Internet | Routing | IP, ICMP |
| Data Link | Network Access | Frame transmission | Ethernet |
| Physical | Network Access | Bit transmission | Physical media |

## Transport Layer Protocols

### 5. TCP (Transmission Control Protocol)

**Characteristics:**
- **Connection-oriented:** Establishes connection before data transfer
- **Reliable:** Guarantees delivery and order
- **Flow control:** Prevents receiver overflow
- **Error detection and correction:** Retransmits lost packets
- **Full-duplex:** Bidirectional communication

**TCP Header Structure:**
```
0                   15                  31
+-------------------+-------------------+
|   Source Port     |   Dest Port       |
+-------------------+-------------------+
|           Sequence Number             |
+--------------------------------------|
|        Acknowledgment Number          |
+--------------------------------------|
|Hdr Len|Reserved|Flags|  Window Size  |
+--------------------------------------|
|   Checksum        |  Urgent Pointer   |
+--------------------------------------|
|              Options                  |
+--------------------------------------|
```

**Three-Way Handshake:**
1. **SYN:** Client sends SYN packet to server
2. **SYN-ACK:** Server responds with SYN-ACK
3. **ACK:** Client sends ACK to complete connection

**Example:**
```
Client → Server: SYN (seq=100)
Server → Client: SYN-ACK (seq=200, ack=101)
Client → Server: ACK (seq=101, ack=201)
Connection established!
```

**Connection Termination (Four-Way Handshake):**
1. **FIN:** Initiator sends FIN
2. **ACK:** Receiver acknowledges FIN
3. **FIN:** Receiver sends its FIN
4. **ACK:** Initiator acknowledges final FIN

### 6. UDP (User Datagram Protocol)

**Characteristics:**
- **Connectionless:** No connection establishment
- **Unreliable:** No guarantee of delivery or order
- **Fast:** Lower overhead
- **Stateless:** No connection state maintained

**UDP Header Structure:**
```
0                   15                  31
+-------------------+-------------------+
|   Source Port     |   Dest Port       |
+-------------------+-------------------+
|   Length          |   Checksum        |
+--------------------------------------|
```

**UDP vs TCP Comparison:**

| Feature | TCP | UDP |
|---------|-----|-----|
| Connection | Connection-oriented | Connectionless |
| Reliability | Reliable | Unreliable |
| Speed | Slower | Faster |
| Overhead | High | Low |
| Use Cases | Web browsing, email | Video streaming, DNS |
| Header Size | 20 bytes | 8 bytes |

## Network Layer

### 7. IP (Internet Protocol)

#### IPv4 Addressing:
**Format:** 32-bit address divided into 4 octets
**Example:** 192.168.1.100

**Classes of IPv4:**

**Class A:**
- Range: 1.0.0.0 to 126.255.255.255
- Network bits: 8, Host bits: 24
- Subnet mask: 255.0.0.0 (/8)
- Max networks: 126, Max hosts: 16,777,214

**Class B:**
- Range: 128.0.0.0 to 191.255.255.255
- Network bits: 16, Host bits: 16
- Subnet mask: 255.255.0.0 (/16)
- Max networks: 16,384, Max hosts: 65,534

**Class C:**
- Range: 192.0.0.0 to 223.255.255.255
- Network bits: 24, Host bits: 8
- Subnet mask: 255.255.255.0 (/24)
- Max networks: 2,097,152, Max hosts: 254

**Private IP Ranges:**
- Class A: 10.0.0.0 to 10.255.255.255
- Class B: 172.16.0.0 to 172.31.255.255
- Class C: 192.168.0.0 to 192.168.255.255

#### Subnetting Example:
**Given:** Network 192.168.1.0/24, create 4 subnets

**Solution:**
- Need 2 bits for 4 subnets (2² = 4)
- New subnet mask: /26 (255.255.255.192)
- Subnet size: 64 addresses each

**Subnets:**
1. 192.168.1.0/26 (192.168.1.0 - 192.168.1.63)
2. 192.168.1.64/26 (192.168.1.64 - 192.168.1.127)
3. 192.168.1.128/26 (192.168.1.128 - 192.168.1.191)
4. 192.168.1.192/26 (192.168.1.192 - 192.168.1.255)

#### IPv6:
**Format:** 128-bit address in hexadecimal
**Example:** 2001:0db8:85a3:0000:0000:8a2e:0370:7334
**Advantages:** Larger address space, better security, auto-configuration

### 8. Routing Protocols

#### Static vs Dynamic Routing:

**Static Routing:**
- Routes configured manually
- Advantages: Simple, secure, low overhead
- Disadvantages: Not scalable, no automatic failover
- Use case: Small networks

**Dynamic Routing:**
- Routes discovered automatically
- Advantages: Scalable, automatic failover
- Disadvantages: Complex, higher overhead
- Types: Distance Vector, Link State

#### Routing Algorithms:

**Distance Vector (RIP):**
- Each router maintains distance table
- Shares table with neighbors periodically
- Uses Bellman-Ford algorithm
- Problem: Count-to-infinity, slow convergence

**Link State (OSPF):**
- Each router maintains network topology
- Floods link state information
- Uses Dijkstra's algorithm
- Advantages: Fast convergence, no loops

**Path Vector (BGP):**
- Used for inter-domain routing
- Maintains path information
- Policy-based routing
- Used in Internet backbone

## Data Link Layer

### 9. Ethernet

**Characteristics:**
- Most common LAN technology
- Uses CSMA/CD (Carrier Sense Multiple Access with Collision Detection)
- Frame format includes preamble, addresses, type, data, FCS

**Ethernet Frame Format:**
```
+----------+----------+----------+----------+----------+----------+
| Preamble | Dest MAC | Src MAC  |   Type   |   Data   |   FCS    |
|  8 bytes |  6 bytes | 6 bytes  | 2 bytes  | 46-1500  | 4 bytes  |
+----------+----------+----------+----------+----------+----------+
```

**CSMA/CD Process:**
1. Listen before transmitting (Carrier Sense)
2. If medium idle, start transmission
3. Monitor for collisions during transmission
4. If collision detected, send jam signal
5. Wait random backoff time before retry

**Ethernet Standards:**
- **10BASE-T:** 10 Mbps over twisted pair
- **100BASE-TX:** 100 Mbps Fast Ethernet
- **1000BASE-T:** 1 Gbps Gigabit Ethernet
- **10GBASE-T:** 10 Gbps Ethernet

### 10. Switching

**MAC Address:**
- 48-bit physical address
- First 24 bits: Organizationally Unique Identifier (OUI)
- Last 24 bits: Device identifier
- Example: 00:1B:44:11:3A:B7

**Switch Operation:**
1. **Learning:** Build MAC address table
2. **Flooding:** Forward unknown destination to all ports
3. **Filtering:** Drop frames destined for same segment
4. **Forwarding:** Send frames to correct port

**VLAN (Virtual LAN):**
- Logical grouping of devices
- Broadcast domain segmentation
- Benefits: Security, performance, flexibility
- Types: Port-based, Tag-based (802.1Q)

## Application Layer Protocols

### 11. HTTP/HTTPS

**HTTP (HyperText Transfer Protocol):**
- Port: 80
- Stateless protocol
- Request-response model
- Methods: GET, POST, PUT, DELETE, HEAD

**HTTP Request Format:**
```
GET /index.html HTTP/1.1
Host: www.example.com
User-Agent: Mozilla/5.0
Accept: text/html
Connection: close
```

**HTTP Response Format:**
```
HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 1234
Server: Apache/2.4

<html>...</html>
```

**HTTPS (HTTP Secure):**
- Port: 443
- HTTP over SSL/TLS
- Provides encryption, authentication, integrity
- Uses digital certificates

**SSL/TLS Handshake:**
1. Client Hello (supported cipher suites)
2. Server Hello (chosen cipher suite, certificate)
3. Client verifies certificate
4. Key exchange and encryption setup
5. Secure communication begins

### 12. DNS (Domain Name System)

**Function:** Translates domain names to IP addresses

**DNS Hierarchy:**
```
Root (.)
├── Top-Level Domains (.com, .org, .in)
├── Second-Level Domains (google.com, tcs.com)
└── Subdomains (www.google.com, mail.google.com)
```

**DNS Resolution Process:**
1. User enters URL in browser
2. Browser checks local DNS cache
3. If not found, query local DNS server
4. Local DNS server queries root server
5. Root server refers to TLD server
6. TLD server refers to authoritative server
7. Authoritative server returns IP address
8. Response propagated back to user

**DNS Record Types:**
- **A:** Maps domain to IPv4 address
- **AAAA:** Maps domain to IPv6 address
- **CNAME:** Canonical name (alias)
- **MX:** Mail exchange server
- **NS:** Name server
- **PTR:** Reverse DNS lookup

### 13. Email Protocols

**SMTP (Simple Mail Transfer Protocol):**
- Port: 25 (587 for submission)
- Used for sending emails
- Commands: HELO, MAIL FROM, RCPT TO, DATA

**POP3 (Post Office Protocol 3):**
- Port: 110 (995 for secure)
- Downloads emails to client
- Emails deleted from server
- Suitable for single device access

**IMAP (Internet Message Access Protocol):**
- Port: 143 (993 for secure)
- Emails stored on server
- Synchronizes across multiple devices
- Supports folders and server-side search

## Network Security

### 14. Security Fundamentals

**CIA Triad:**
- **Confidentiality:** Information accessible only to authorized users
- **Integrity:** Information remains unaltered
- **Availability:** Information accessible when needed

**Common Threats:**
- **Eavesdropping:** Intercepting communication
- **Man-in-the-Middle:** Intercepting and modifying communication
- **Denial of Service (DoS):** Making resources unavailable
- **Malware:** Viruses, worms, trojans
- **Social Engineering:** Manipulating users

### 15. Cryptography

**Symmetric Encryption:**
- Same key for encryption and decryption
- Fast, suitable for large data
- Key distribution problem
- Examples: AES, DES

**Asymmetric Encryption:**
- Different keys for encryption and decryption
- Public key for encryption, private key for decryption
- Slower than symmetric
- Examples: RSA, ECC

**Digital Signatures:**
- Provides authentication and non-repudiation
- Sender signs with private key
- Receiver verifies with public key

**Hash Functions:**
- One-way functions
- Fixed output size
- Examples: SHA-256, MD5
- Uses: Data integrity, password storage

## Wireless Networks

### 16. Wi-Fi (IEEE 802.11)

**Standards Evolution:**
- **802.11:** 2 Mbps (1997)
- **802.11b:** 11 Mbps (1999)
- **802.11g:** 54 Mbps (2003)
- **802.11n:** 150-600 Mbps (2009)
- **802.11ac:** 433 Mbps - 6.93 Gbps (2013)
- **802.11ax (Wi-Fi 6):** Up to 9.6 Gbps (2019)

**CSMA/CA (Collision Avoidance):**
1. Listen before transmitting
2. If medium busy, wait random backoff
3. Send RTS (Request to Send)
4. Receive CTS (Clear to Send)
5. Transmit data
6. Receive ACK

**Wi-Fi Security:**
- **WEP:** Weak, deprecated
- **WPA:** Better than WEP but vulnerable
- **WPA2:** Current standard, uses AES
- **WPA3:** Latest, enhanced security

### 17. Cellular Networks

**Generations:**
- **1G:** Analog voice (AMPS)
- **2G:** Digital voice, SMS (GSM, CDMA)
- **3G:** Mobile data (UMTS, CDMA2000)
- **4G/LTE:** High-speed data (up to 1 Gbps)
- **5G:** Ultra-fast, low latency (up to 20 Gbps)

## Network Troubleshooting

### 18. Common Network Tools

**ping:**
- Tests connectivity using ICMP
- Example: `ping google.com`
- Shows round-trip time and packet loss

**traceroute/tracert:**
- Shows path packets take to destination
- Identifies where delays occur
- Example: `traceroute google.com`

**netstat:**
- Shows network connections and listening ports
- Example: `netstat -an`

**nslookup/dig:**
- DNS lookup tools
- Example: `nslookup google.com`

**wireshark:**
- Network packet analyzer
- Captures and analyzes network traffic

### 19. Common Network Issues

**High Latency:**
- Causes: Network congestion, routing issues, distance
- Solutions: Optimize routing, upgrade bandwidth, use CDN

**Packet Loss:**
- Causes: Network congestion, faulty hardware, interference
- Solutions: Check cables, upgrade equipment, reduce congestion

**DNS Issues:**
- Causes: DNS server problems, configuration errors
- Solutions: Change DNS servers, flush DNS cache

**Connectivity Issues:**
- Causes: Physical problems, configuration errors, security settings
- Solutions: Check physical connections, verify IP configuration

## Interview Questions with Detailed Answers

### Basic Networking Questions:

**Q1: Explain the difference between hub, switch, and router.**

**Answer:**

**Hub:**
- Physical layer device (Layer 1)
- Creates single collision domain
- Half-duplex communication
- Broadcasts to all ports
- Largely obsolete

**Switch:**
- Data link layer device (Layer 2)
- Each port is separate collision domain
- Full-duplex communication
- Maintains MAC address table
- Forwards based on MAC addresses

**Router:**
- Network layer device (Layer 3)
- Connects different networks
- Makes routing decisions based on IP addresses
- Maintains routing table
- Provides NAT, DHCP, firewall features

**Q2: What happens when you type www.google.com in browser?**

**Answer:**
1. **DNS Resolution:**
   - Browser checks cache for IP address
   - If not found, queries DNS server
   - DNS server returns IP address (e.g., 142.250.190.78)

2. **TCP Connection:**
   - Browser initiates TCP connection to server (port 80/443)
   - Three-way handshake establishes connection

3. **HTTP Request:**
   - Browser sends HTTP GET request
   - Request includes headers (User-Agent, Accept, etc.)

4. **Server Processing:**
   - Web server receives and processes request
   - Generates HTML response

5. **HTTP Response:**
   - Server sends response with status code and content
   - May include CSS, JavaScript, images

6. **Rendering:**
   - Browser parses HTML and builds DOM
   - Loads additional resources (CSS, JS, images)
   - Renders page for user

**Q3: Explain subnetting with an example.**

**Answer:**
**Scenario:** Company has network 192.168.10.0/24 and needs 6 departments

**Solution:**
- Need 3 bits for 8 subnets (2³ = 8, covers 6 departments)
- New subnet mask: /27 (255.255.255.224)
- Each subnet has 30 usable addresses (32 - 2)

**Subnets:**
1. Sales: 192.168.10.0/27 (192.168.10.1 - 192.168.10.30)
2. HR: 192.168.10.32/27 (192.168.10.33 - 192.168.10.62)
3. IT: 192.168.10.64/27 (192.168.10.65 - 192.168.10.94)
4. Finance: 192.168.10.96/27 (192.168.10.97 - 192.168.10.126)
5. Marketing: 192.168.10.128/27 (192.168.10.129 - 192.168.10.158)
6. Operations: 192.168.10.160/27 (192.168.10.161 - 192.168.10.190)

### Advanced Questions:

**Q4: How does DHCP work?**

**Answer:**
**DHCP (Dynamic Host Configuration Protocol)** automatically assigns IP addresses to devices.

**DHCP Process (DORA):**
1. **Discover:** Client broadcasts DHCPDISCOVER
2. **Offer:** DHCP server responds with DHCPOFFER
3. **Request:** Client sends DHCPREQUEST for offered IP
4. **Acknowledge:** Server sends DHCPACK confirming assignment

**DHCP Components:**
- **DHCP Server:** Manages IP address pool
- **DHCP Client:** Requests IP configuration
- **DHCP Relay:** Forwards DHCP messages across subnets
- **IP Address Pool:** Range of available addresses

**Lease Process:**
- Addresses assigned for specific time period
- Client must renew lease before expiration
- Server can reclaim expired addresses

**Q5: Explain how NAT works.**

**Answer:**
**NAT (Network Address Translation)** allows multiple devices to share single public IP address.

**Types of NAT:**

**Static NAT:**
- One-to-one mapping
- Private IP permanently mapped to public IP
- Used for servers requiring external access

**Dynamic NAT:**
- Pool of public IPs assigned dynamically
- Private IP gets any available public IP
- Mapping exists only during communication

**PAT (Port Address Translation):**
- Many-to-one mapping using ports
- Most common in home/office routers
- Single public IP serves multiple private IPs

**NAT Process:**
1. Internal device sends packet to external destination
2. Router replaces source IP with public IP
3. Router stores mapping in NAT table
4. External response arrives at router
5. Router looks up destination in NAT table
6. Router forwards packet to internal device

**Example:**
```
Internal: 192.168.1.100:5000 → External: 8.8.8.8:53
NAT Table: 203.0.113.1:12345 ↔ 192.168.1.100:5000
External sees: 203.0.113.1:12345 → 8.8.8.8:53
```

### Security Questions:

**Q6: What is a firewall and how does it work?**

**Answer:**
**Firewall** is a security device that monitors and controls network traffic based on predetermined rules.

**Types of Firewalls:**

**Packet Filter:**
- Examines packet headers
- Filters based on IP, port, protocol
- Stateless operation
- Fast but limited security

**Stateful Firewall:**
- Tracks connection state
- Maintains session table
- Better security than packet filter
- Can detect connection hijacking

**Application Gateway:**
- Operates at application layer
- Deep packet inspection
- Can filter based on content
- Higher overhead but maximum security

**Firewall Rules Example:**
```
Rule 1: Allow HTTP (port 80) from any to web server
Rule 2: Allow HTTPS (port 443) from any to web server
Rule 3: Allow SSH (port 22) from admin network to servers
Rule 4: Deny all other traffic
```

**Q7: Explain VPN and its types.**

**Answer:**
**VPN (Virtual Private Network)** creates secure connection over public network.

**Types of VPN:**

**Site-to-Site VPN:**
- Connects two networks
- Permanent connection
- Used for branch offices
- Protocols: IPSec, GRE

**Remote Access VPN:**
- Individual users connect to network
- On-demand connection
- Used for remote workers
- Protocols: PPTP, L2TP, SSL/TLS

**VPN Protocols:**

**IPSec:**
- Network layer protocol
- Provides encryption and authentication
- Two modes: Transport and Tunnel
- Commonly used for site-to-site VPN

**SSL/TLS VPN:**
- Application layer protocol
- Browser-based access
- No client software required
- Used for remote access

**VPN Benefits:**
- Data encryption
- Secure remote access
- Bypass geo-restrictions
- Cost-effective WAN alternative

## Network Performance and QoS

### 20. Quality of Service (QoS)

**QoS Parameters:**
- **Bandwidth:** Data transmission capacity
- **Latency:** Time for packet to travel from source to destination
- **Jitter:** Variation in packet delay
- **Packet Loss:** Percentage of packets not delivered

**QoS Techniques:**

**Traffic Shaping:**
- Controls rate of traffic flow
- Smooths burst traffic
- Prevents network congestion

**Traffic Policing:**
- Monitors traffic rate
- Drops or marks excess traffic
- Enforces traffic contracts

**Priority Queuing:**
- Different queues for different traffic types
- High-priority traffic served first
- Ensures critical applications get bandwidth

**Example QoS Implementation:**
```
Queue 1 (High Priority): VoIP traffic
Queue 2 (Medium Priority): Video streaming
Queue 3 (Low Priority): File downloads
Queue 4 (Lowest Priority): Backup traffic
```

## Modern Networking Trends

### 21. Software-Defined Networking (SDN)

**Traditional Network:**
- Control and data planes integrated
- Distributed control
- Vendor-specific configuration

**SDN Architecture:**
- Centralized control plane
- Programmable network
- Open standards (OpenFlow)

**Benefits:**
- Centralized management
- Dynamic configuration
- Vendor independence
- Innovation acceleration

### 22. Cloud Networking

**Cloud Service Models:**
- **IaaS:** Infrastructure as a Service
- **PaaS:** Platform as a Service
- **SaaS:** Software as a Service

**Network Virtualization:**
- Virtual switches and routers
- Software-defined WANs
- Overlay networks
- Multi-tenancy support

## Quick Reference for Interview

### Important Port Numbers:
```
FTP: 20 (data), 21 (control)
SSH: 22
Telnet: 23
SMTP: 25
DNS: 53
HTTP: 80
POP3: 110
NNTP: 119
NTP: 123
IMAP: 143
SNMP: 161
HTTPS: 443
```

### Subnet Mask Quick Reference:
```
/8  = 255.0.0.0     (16,777,214 hosts)
/16 = 255.255.0.0   (65,534 hosts)
/24 = 255.255.255.0 (254 hosts)
/25 = 255.255.255.128 (126 hosts)
/26 = 255.255.255.192 (62 hosts)
/27 = 255.255.255.224 (30 hosts)
/28 = 255.255.255.240 (14 hosts)
/30 = 255.255.255.252 (2 hosts)
```

### Network Troubleshooting Commands:
```bash
ping -c 4 google.com          # Test connectivity
traceroute google.com         # Show network path
netstat -an                   # Show connections
ss -tuln                      # Show listening ports
nslookup google.com           # DNS lookup
dig google.com                # Advanced DNS lookup
arp -a                        # Show ARP table
route -n                      # Show routing table
ifconfig                      # Network interface info
ip addr show                  # Modern interface info
```

## Interview Preparation Tips

### Key Areas to Focus:
1. **OSI Model:** Understand each layer and protocols
2. **TCP/IP:** Know the differences and use cases
3. **Routing:** Understand how packets find their destination
4. **Switching:** Know how LANs work
5. **IP Addressing:** Master subnetting calculations
6. **DNS:** Understand how domain resolution works
7. **Security:** Know basic concepts and protocols
8. **Troubleshooting:** Practice with common tools

### Common Mistakes to Avoid:
- Confusing layers in OSI model
- Not understanding the difference between routing and switching
- Mixing up TCP and UDP characteristics
- Incorrect subnetting calculations
- Not knowing common port numbers
- Confusing NAT with proxy servers

### Practice Strategy:
1. **Memorize basics:** OSI layers, protocols, port numbers
2. **Practice calculations:** Subnetting, VLSM
3. **Understand protocols:** How they work, not just what they do
4. **Draw diagrams:** Network topologies, protocol stacks
5. **Troubleshoot scenarios:** Practice problem-solving approach
6. **Stay current:** Learn about SDN, cloud networking, 5G