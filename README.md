# 🛡️ SecureBox Kit

**Hands-on cybersecurity training toolkit for embedded systems, industrial gateways, and secure IoT deployments.**

Developed and maintained by **Technopont**.

---

[![Docker](https://img.shields.io/badge/Docker-Docker%20Compose-blue.svg?logo=docker&logoColor=white)](https://github.com/technopont/securebox-kit)
[![Python](https://img.shields.io/badge/Python-3.8%2B-blue.svg?logo=python&logoColor=white)](https://github.com/technopont/securebox-kit)
[![Hardware](https://img.shields.io/badge/Hardware-ESP32%20%7C%20STM32-orange.svg)](https://github.com/technopont/securebox-kit)
[![MQTT](https://img.shields.io/badge/MQTT-Mosquitto%20mTLS-red.svg?logo=eclipse-mosquitto)](https://github.com/technopont/securebox-kit)
[![Crypto](https://img.shields.io/badge/Crypto-OpenSSL%20%2F%20PKI-green.svg)](https://github.com/technopont/securebox-kit)
[![Compliance](https://img.shields.io/badge/Principles-CRA%20%26%20NIS2%20Principles-success.svg)](https://github.com/technopont/securebox-kit)

> ⚠️ **Disclaimer:** This repository contains educational material intended exclusively for defensive cybersecurity training, academic exercises, and security awareness. Any unauthorized use of these tools, scripts, or techniques on systems you do not own or have explicit permission to audit is strictly prohibited.

---

**SecureBox Kit serves as the official practical training environment of the SecureBox IoT Academy.**

This repository provides the core configuration templates, source files, and automation scripts used in our hands-on laboratories to study firmware security, public key infrastructures, and system hardening.

---

## 🚧 Project Status

This repository is under active development. Lab templates, firmware samples, and verification scripts evolve alongside our new training module releases.

---

## 📌 Note

This repository does not include production credentials, real devices, or live infrastructure. All environments are simulated and intended for educational use only.

---

## 🧭 Scope & Objectives

This repository focuses on defensive cybersecurity training, local systems hardening, and secure architecture design. All laboratory modules, network configurations, and cryptographic certificates are engineered strictly for educational and local sandboxed testing purposes.

---

## 🎯 Toolkit Overview

*   **✔ Firmware Security:** ESP32 & STM32 static binary audits, header inspection, and secure boot concepts.
*   **✔ PKI & Cryptography:** Custom local Certificate Authority (CA) creation, OpenSSL automation, and mTLS client-certificate lifecycles.
*   **✔ Broker Hardening:** MQTT transport encryption, client verification policies, and Certificate Revocation Lists (CRL).
*   **✔ Gateway Defense:** Multi-container isolation, read-only file systems, and minimal user execution environments.
*   **✔ Low-level Watchdogs:** Embedded microcontroller C-code for network rate-limiting and active packet filtering.
*   **✔ Regulatory Frameworks:** Exercises designed to support training aligned with the security principles of the **EU Cyber Resilience Act (CRA)** and the **NIS2 Directive**.

---

## 📋 Table of Contents

1. [About SecureBox Kit](#-about-securebox-kit)
2. [SecureBox IoT Academy](#-securebox-iot-academy)
3. [Repository Structure](#-repository-structure)
4. [Getting Started](#-getting-started)
5. [Local Audit Tools](#-local-audit-tools)
6. [Copyright & Contact](#-copyright--contact)

---

## 🛡️ About SecureBox Kit

**SecureBox Kit** is an interactive, industry-focused training repository designed to help systems engineers, firmware developers, and security professionals build defense-in-depth security architectures for IoT devices and industrial gateways.

By bridging theoretical security concepts (such as STRIDE threat modeling) with practical command-line exercises, developers learn how to mitigate vulnerabilities on resource-constrained microcontrollers and local gateway systems before deploying to production.

---

## 🎓 SecureBox IoT Academy

The **SecureBox IoT Academy** is a comprehensive, interactive e-learning platform that leverages the files in this repository to run simulated sandboxes and firmware analysis pipelines.

Through our structured syllabus, students learn to audit laboratory environments and harden them step-by-step using modern industrial standards.

---

## 📁 Repository Structure

```text
securebox-kit/
├── docker/                         # Gateway environment, broker and sensor configurations
│   ├── mosquitto-secure.conf       # Hardened Mosquitto configuration template
│   └── docker-compose.yml          # Multi-container orchestration template
├── firmware/                       # Microcontroller binary analysis targets
│   └── firmware_sample.bin         # Target firmware binary for static audits
├── pki/                            # Public Key Infrastructure assets
│   └── generate_pki_certs.sh       # OpenSSL CA & client/server certificate generator
├── templates/                      # Student templates and lab sheets
│   ├── matrice_stride_iot.xlsx     # STRIDE risk assessment template
│   └── rapport_incident.md         # Incident reporting and forensic log template
├── tools/                          # Security audit and verification scripts
│   └── check_firmware_signatures.py # Static binary signature checker
└── watchdog/                       # Real-time hardware security modules
    └── secure_watchdog.c           # Low-level MCU network rate-limiting source code
```

---

## 🚀 Getting Started

### 1. Prerequisites

Ensure you have the following installed on your host system:
*   **Linux (Ubuntu/Debian recommended)** or macOS.
*   **Docker** & **Docker Compose v2**
*   **Python 3.8+** (for audit scripts)
*   **OpenSSL** (for PKI certificate generation)

### 2. Clone the Workspace

```bash
# Clone the official Technopont SecureBox repository
git clone https://github.com/technopont/securebox-kit.git

# Navigate to the workspace
cd securebox-kit
```

### 3. Initialize the Sandbox

Spin up the localized Docker sandbox which emulates an industrial sensor sending telemetry to a central gateway:

```bash
# Start the broker, sensor, and gateway
docker compose -f docker/docker-compose.yml up -d
```

---

## ⚙️ Local Audit Tools

This kit features built-in verification scripts that students can execute to measure progress and inspect system configurations.

### Firmware Signature Audit

Use `check_firmware_signatures.py` to inspect firmware binaries for secure hardware headers:

```bash
python3 tools/check_firmware_signatures.py firmware/firmware_sample.bin
```

---

## 🔒 Copyright & Contact

© **Technopont**  
All Rights Reserved.

Access to hands-on solutions and physical training microcontroller boards is managed by the **SecureBox IoT Academy**.

For enterprise subscriptions, customized team trainings, or partnership inquiries, please contact us at:  
📧 **support@technopont.fr**
