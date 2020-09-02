## Steps to configure

- Check network IP by ifconfig. Let's instance it's eno1: 10.2.16.239

- Add two networks in ~/etc/networks
    - snullnet0 10.2.16.0
    - snullnet1 10.2.17.0

- Add Host in ~/etc/hosts
    
    - 10.2.16.1     local0
    - 10.2.16.2     remote0   
    - 10.2.17.2     local1
    - 10.2.17.1     remote1

- Make sure the module snull is inserted into the kernel.

- As IP is not of class C so we have to add netmask.
    sudo ifconfig sn0 local0 netmask 255.255.255.0
    sudo ifconfig sn1 local1 netmask 255.255.255.0

- Check connection by Ping from host(your-PC) to virtual host(remote0/remote1). (Optional)
    - sudo ping -c 2 remote0
    - sudo ping -c 2 remote1

- Ping both virtual host with one another.
    - sudo ping -I sn0 10.2.17.1
    - sudo ping -I sn1 10.2.16.2

- To make Loopback interface down
    - ifconfig lo down


![screenshot](images/q5-ref.png)