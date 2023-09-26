# qem-os (Operating System)
### The next ultimate performance operating system, Build on top of `C++`, `C` and `Assembly` for `x86_64` Architecture.
### The current goal:
- User Interface That is Fully Customizeable (Smooth by default)
- Add Rust Programming Language Support
- Applications built-in Rust (To get the ultimate performance)
- For all categories, Especially `Programming`
- Uses `ext4` file system (The most default file system for linux)
- Have the lowest device requirements (Can run on a potato that supports `x64 architecture`)

---------

# How to build & run

## `Windows`
- You need any debian based wsl2 (Ubuntu 22.x Recommended) [WSL2](https://learn.microsoft.com/en-us/windows/wsl/install)
- After that launch it and setup your profile.
- Now run these commands :
  - ```console
    $ sudo apt-get update -y
    ```
  - ```console
    $ sudo apt-get upgrade -y
    ```
  - ```console
    $ sudo apt-get g++ -y
    ```
  - ```console
    $ sudo apt-get install -y nasm
    ```
  - ```console
    $ sudo apt-get install -y xorriso
    ```
  - ```console
    $ sudo apt-get install -y grub-efi-amd64
    ```
  - ```console
    $ sudo apt-get install -y grub-common
    ```
  - ```console
    $ sudo apt-get install -y make
    ```
  - ```console
    $ sudo apt-get install -y mtools
    ```
- Then install **qemu** on your real machine, Follow how to install it [here.](https://www.minitool.com/partition-disk/qemu-for-windows.html)
- Now when in the wsl, Enter the project directory and run 
  - ```console
    $ make build-x86_64
    ```
- Now you have your **iso** file in `dist/x86_64/`
- Now on your real machine cmd, Go to the project directory and run
  - ```console
    $ qemu-system-x86_64 dist/x86_64/kernel.iso
    ```
- Now you have built it and it's running!

## `Linux`
- Run these commands :
  - ```console
    $ sudo apt-get update -y
    ```
  - ```console
    $ sudo apt-get upgrade -y
    ```
  - ```console
    $ sudo apt-get g++ -y
    ```
  - ```console
    $ sudo apt-get install -y nasm
    ```
  - ```console
    $ sudo apt-get install -y xorriso
    ```
  - ```console
    $ sudo apt-get install -y grub-efi-amd64
    ```
  - ```console
    $ sudo apt-get install -y grub-common
    ```
  - ```console
    $ sudo apt-get install -y make
    ```
  - ```console
    $ sudo apt-get install -y mtools
    ```
- Then install **qemu** on, Follow how to install it [here.](https://www.qemu.org/download/#linux)
- Now in the project directory run 
  - ```console
    $ make build-x86_64
    ```
- Now you have your **iso** file in `dist/x86_64/`
- Now open the terminal, Go to the project directory and run
  - ```console
    $ qemu-system-x86_64 dist/x86_64/kernel.iso
    ```
- Now you have built it and it's running!

# `MacOS`
- For installing `gcc`, `nasm`, `xorriso` and `make`
- Using **homebrew**
  -  ```console
     $ brew install gcc nasm xorriso make
     ```
- For `grub-efi-amd64` `grub-common` Please search it in google, idk
- We need to also install `qemu` to run the `iso` file
  - Using **Homebrew**
    - ```console
       $ brew install qemu
       ```
  - Using **MacPorts**
    -  ```console
        $ sudo port install qemu
        ```