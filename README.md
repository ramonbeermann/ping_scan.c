# 🔍 Hash Scanner & Virus Detector in C

A **fast and efficient hash scanner** that recursively scans all files on a system, computes **MD5, SHA-1, and SHA-256** hashes, and checks them against a **malware hash database**.

## 🚀 Features
- ✅ **Recursive file scanning** across directories
- ✅ **Multi-threaded processing** for faster scanning
- ✅ **MD5, SHA-1, and SHA-256 hashing** for security verification
- ✅ **Virus detection** using a local database (`virus_hashes.txt`)
- ✅ **Cross-platform support** (Linux, macOS, Windows)

---

## ⚙️ Installation & Compilation

### **Linux/macOS (GCC)**
```bash
gcc hash_scanner.c -o hash_scanner -pthread -lcrypto
./hash_scanner
### **Windows (MinGW)**
gcc hash_scanner.c -o hash_scanner.exe -lpthread -lcrypto
hash_scanner.exe
```


## 🛠️ How It Works

    1. The scanner recursively finds all files in the target directory.
    2. Computes multiple hashes (MD5, SHA-1, SHA-256).
    3. Compares hashes with the virus database (virus_hashes.txt).
    4. Flags suspicious files if their hash matches a known malware signature.
##📡 Usage

1️⃣ Run the program:
```bash
./hash_scanner
```
2️⃣ Enter the directory to scan:
🔎 HASH-VIRUS SCANNER 🔍
📂 Enter the directory to scan (e.g., /home/user):

3️⃣ If a virus is found:
⚠️ VIRUS DETECTED: /home/user/malware.exe ❌

##📌 Example virus_hashes.txt (Malware Hash Database)

d41d8cd98f00b204e9800998ecf8427e  # Example MD5 hash
3b5d5c3712955042212316173ccf37be
b1946ac92492d2347c6235b4d2611184

##🔬 To-Do / Future Features

VirusTotal API integration for online hash verification
Heuristic analysis for unknown threats
GUI interface for easier use
