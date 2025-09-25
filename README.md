A small project for practicing **Data Structures & Algorithms** in C.  
It handles users and jobs, saves them to a file, and loads them back again.  
Think of it as a basic job-management database built with C.  

---

 What it does
- Lets you **register users** with a username and password.  
- Stores users in a **hash table**.  
- Lets users store **jobs**, with insert/delete functionality.  
- Uses **File I/O** to save users and load them back on program start.  

Zoom in on the code, and you’ll see all the classic DSA concepts:
- Hash tables  
- Linked lists  
- Modular design (separate `.c` and `.h` files)  

---

 Running it
You need a C compiler (GCC / G++) and optionally Code::Blocks.  

**Command line run:**
```bash
g++ -Wall -g -o projectDSA fileio.c job.c user.c main.c
./projectDSA
