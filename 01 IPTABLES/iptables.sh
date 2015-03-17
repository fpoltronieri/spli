#!/bin/bash
#
#	Iptables Rules
#

echo 'Ciao Bel'

dafault="10.10.10."
mike=$default"20"
marco=$default"X"
marci=$default"Y"
pedro=$default"Z"
router=$default"10"

# External Public Interface
EXTIN="eth0"

# Internal Private Interface
INTIN="wlan0"

# Internal IPs
INTIPS=$default"0/24"

iptables -F
iptables -X
iptables -Z
iptables -t nat -F
iptables -t nat -X
iptables -t mangle -F
iptables -t mangle -X
iptables -P INPUT ACCEPT
iptables -P OUTPUT ACCEPT
iptables -P FORWARD ACCEPT


 
# 10.10.10.X pinga 10.10.10.139
# 10.10.10.X vede che il ping e tra lui e 10.10.10.214
#
#iptables -t nat -A PREROUTING -i wlan0 -p tcp --dport 80 -d 10.10.10.11 -s 10.10.10.0/24 -j DNAT --to-destination 10.10.10.1:8000
#iptables -t nat -A PREROUTING -i wlan0 -p tcp --dport 80 -j DNAT --to-destination 10.10.10.1:80


# 10.10.10.139 pinga 10.10.10.X
# 10.10.10.X vede che sta pingando con 10.10.10.214
#
# se 10.10.10.139 pinga 10.10.10.214
# 10.10.10.214 vede che pinga con se stesso
#iptables -t nat -A POSTROUTING -s 10.10.10.11 -j SNAT --to-source 10.10.10.9

#
# Droppo tutto tranne quello che arriva da 10.10.10.140
#
#iptables -P INPUT DROP
#iptables -A INPUT -s 10.10.10.9 -j ACCEPT
#
#Droppo tutto tranne quello che esce dalla porta 80
#
#iptables -P OUTPUT DROP
#iptables

iptables -A FORWARD -i $INTIF -o $EXTIF -j ACCEPT

iptables -t nat -A POSTROUTING -s $INTIPS -j MASQUERADE
