# qem os

# How to build & run

## `Windows`
- You need any debian based wsl2 (Ubuntu 22.x Recommended) [Ubuntu WSL2](https://learn.microsoft.com/en-us/windows/wsl/install)
- After that launch it and setup your profile.
- Now run these commands :
  - ```console
    sudo apt-get update -y
    ```
  - ```console
    sudo apt-get upgrade -y
    ```
  - ```console
    sudo apt-get g++ -y
    ```
  - ```console
    sudo apt-get install -y nasm
    ```
  - ```console
    sudo apt-get install -y xorriso
    ```
  - ```console
    sudo apt-get install -y grub-pc-bin
    ```
  - ```console
    sudo apt-get install -y grub-common
    ```
  - ```console
    sudo apt-get install -y make
    ```
- Then install **qemu** on your real machine, Follow how to install it [here.](https://www.minitool.com/partition-disk/qemu-for-windows.html)
- Now when in the wsl, Enter the project directory and run 
  - ```console
    make build-x86_64
    ```
- Now you have your **iso** file in `dist/x86_64/`
- Now on your real machine cmd, Go to the project directory and run
  - ```console
    qemu-system-x86_64 dist/x86_64/kernel.iso
    ```
- Now you have built it and it's running!

## `Linux`
- Run these commands :
  - ```console
    sudo apt-get update -y
    ```
  - ```console
    sudo apt-get upgrade -y
    ```
  - ```console
    sudo apt-get g++ -y
    ```
  - ```console
    sudo apt-get install -y nasm
    ```
  - ```console
    sudo apt-get install -y xorriso
    ```
  - ```console
    sudo apt-get install -y grub-pc-bin
    ```
  - ```console
    sudo apt-get install -y grub-common
    ```
  - ```console
    sudo apt-get install -y make
    ```
- Then install **qemu** on, Follow how to install it [here.](https://www.qemu.org/download/#linux)
- Now in the project directory run 
  - ```console
    make build-x86_64
    ```
- Now you have your **iso** file in `dist/x86_64/`
- Now open the terminal, Go to the project directory and run
  - ```console
    qemu-system-x86_64 dist/x86_64/kernel.iso
    ```
- Now you have built it and it's running!