# Am0rpheus 
An aggressive cryptomining malware that loads an autonomous cryptomining trojan by using a 0day in dnsrecords. Including optional vuln-scanner. 

Once the pre-loader connects through an available dns, it sends some prefetch shellcode to load the polymorphic loader body. The polymorphic 1-st gen loader builds the trojan and adds it to the loader body. 2nd gen is born now. The malware will bypass some av's and firewalls and will then quickly replicate to other machines in the same subnet. Once the trojan finds other zombies in the net, it will connect via socket and the start mining some
cryptocurrencies. Neat!
