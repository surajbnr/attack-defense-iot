# attack-defense-iot
A basic simulation of a DoS attack on an IoT system, along with a simple defense mechanism to block the attacker.

Project Structure

-iot_proj/ – Hosts an HTTP webpage displaying IR sensor data via ESP32

-attackers_pov.py – Simulates a DoS attack using a Raspberry Pi

-iot_proj_defence/ – Detects and blocks the attacker's IP address

System Overview

-An ESP32 board connected to an IR sensor sends data to a web server. A Raspberry Pi, on the same network, performs a DoS attack by flooding the server with requests. The defense mechanism identifies and blocks the attacker's IP, restoring system stability.

Purpose

-To demonstrate basic IoT security concepts, including attack detection and IP-based access control.
