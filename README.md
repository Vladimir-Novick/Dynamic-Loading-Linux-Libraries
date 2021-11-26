# Dynamic-Loading-Linux-Libraries
Dynamic loading c++ from multiple Linux libraries

Dynamically loaded libraries are libraries that are loaded at times other than during the startup of a program.
They're particularly useful for implementing plugins or modules, because they permit waiting to load the plugin until it's needed.




## 1) 1.1 Install standard Nodejs ( v10.x )

        $ sudo apt update
        $ sudo apt install nodejs
        $ sudo npm install --global npm@latest
        $ node -v

### 1.2    Installing Node.js with Apt Using a NodeSource PPA ( v12, v14, and v16 )

    1.2.1 install nodeJs v16

        These PPAs have more versions of Node.js available than the official Ubuntu repositories. Node.js v12, v14, and v16 are available as of the time of writing. 

         $ cd ~
         $ curl -sL https://deb.nodesource.com/setup_16.x -o nodesource_setup.sh
         $ sudo apt update
         $ sudo bash nodesource_setup.sh
         $ sudo apt-get install -y nodejs
         $ sudo npm install --global npm@latest
         $ node -v

     1.2.1 install the Yarn package manage:

         $ curl -sL https://dl.yarnpkg.com/debian/pubkey.gpg | gpg --dearmor | sudo tee /usr/share/keyrings/yarnkey.gpg >/dev/null

         $ sudo apt-get update && sudo apt-get install yarn


## 2) install node-gyp to NodeJs 

        $ sudo npm install --global npm@latest
        $ sudo npm install --global node-gyp@latest
        $ sudo npm config set node_gyp $(npm prefix -g)/lib/node_modules/node-gyp/bin/node-gyp.js
        $ python3 --version
        $ python3 -m pip --version


## 3) install Python  v3.8, or v3.9  

        3.1.1 - install:

                $ sudo apt-get install software-properties-common
                $ sudo add-apt-repository ppa:deadsnakes/ppa
                $ sudo apt-get update
                $ sudo apt-get install python3.8

            3.1.2 - check python

                $ python3 --version
                $ python3 -m pip --version
            
        3.2 install Setuptools & Pip
            The two most crucial third-party Python packages are setuptools and pip.
            Python  v3.8 include pip by default.

            To see if pip is installed, open a command prompt and run
            $ command -v pip3


## 4) development tools to build native addons: 
            
            4.1 GCC

                $ sudo apt-get update
                $ sudo apt-get install gcc g++ make

            4.2  build-essential   

                $ sudo apt-get update 
                $ sudo apt install build-essential

            4.3 Check G++ version

                $ g++ --version

## 5) Installing Visual Studio Code 

            5.2) for Ubuntu-Desktop

                $ sudo apt update
                $ sudo apt install software-properties-common apt-transport-https wget
                $ wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
                $ sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
                $ sudo apt install code
                $ sudo apt update
                $ sudo apt upgrade

            5.1) install remote wsl to VS code to WSL

                https://code.visualstudio.com/docs/remote/wsl-tutorial


 ## 6)   Install Git

          6.1)  Git is likely already installed in your Ubuntu 20.04 server  

                $ git --version
                    
                        Output
                        git version 2.25.1

                    $ sudo apt update  
                    $ sudo apt install git  

          6.2) Setting Up Git 

            $ git config --global user.name "Your Name"
            $ git config --global user.email "youremail@domain.com"
            $ git config --list
            $ nano ~/.gitconfig

 ## 7)  Gitlab integration

         $ ssh-keygen -t ed25519
              ( empty for no passphrase)

         $ nano /home/vlad/.ssh/id_ed25519.pub

         ( copy contents and insert to website gitlab : preferenses -> user settings -> SSH keys  )

 ## Setting up WSL to Visual Studio 2019

        sudo apt update
        sudo apt install g++ gdb make ninja-build rsync zip    

        sudo dpkg-reconfigure openssh-server

        sudo /usr/sbin/sshd -Dddde

        output:
            debug2: load_server_config: filename /etc/ssh/sshd_config
            debug2: load_server_config: done config len = 371
            debug2: parse_server_config_depth: config /etc/ssh/sshd_config len 371
            debug2: /etc/ssh/sshd_config line 13: new include /etc/ssh/sshd_config.d/*.conf
            debug2: /etc/ssh/sshd_config line 13: no match for /etc/ssh/sshd_config.d/*.conf
            debug3: /etc/ssh/sshd_config:15 setting Port 2828
            debug3: /etc/ssh/sshd_config:16 setting AddressFamily any
            debug3: /etc/ssh/sshd_config:17 setting ListenAddress 127.0.0.1
            debug3: /etc/ssh/sshd_config:58 setting PasswordAuthentication yes
            debug3: /etc/ssh/sshd_config:63 setting ChallengeResponseAuthentication no
            debug3: /etc/ssh/sshd_config:86 setting UsePAM yes
            debug3: /etc/ssh/sshd_config:91 setting X11Forwarding yes
            debug3: /etc/ssh/sshd_config:95 setting PrintMotd no
            debug3: /etc/ssh/sshd_config:113 setting AcceptEnv LANG LC_*
            debug3: /etc/ssh/sshd_config:116 setting Subsystem sftp /usr/lib/openssh/sftp-server
            debug1: sshd version OpenSSH_8.2, OpenSSL 1.1.1f  31 Mar 2020
            debug1: private host key #0: ssh-rsa ?????????????????????????
            debug1: private host key #1: ecdsa-sha2-????????????????????????????
            debug1: private host key #2: ssh-ed25519 ????????????????????????????
            debug1: rexec_argv[0]='/usr/sbin/sshd'
            debug1: rexec_argv[1]='-Dddde'
            debug3: oom_adjust_setup
            debug1: Set /proc/self/oom_score_adj from 0 to -1000
            debug2: fd 3 setting O_NONBLOCK
            debug1: Bind to port 2828 on 127.0.0.1.
            Bind to port 2828 on 127.0.0.1 failed: Address already in use.
            Cannot bind any address.

#### ssh status
           sudo  systemctl status sshd

           sudo systemctl daemon-reload

    if got this error:
            System has not been booted with systemd as init system (PID 1). Can't operate. Failed to connect to bus: Host is down
    try it:

            sudo apt-get update && sudo apt-get install -yqq daemonize dbus-user-session fontconfig
            sudo daemonize /usr/bin/unshare --fork --pid --mount-proc /lib/systemd/systemd --system-unit=basic.target
            exec sudo nsenter -t $(pidof systemd) -a su - $LOGNAME
            snap version

            sudo dpkg-reconfigure openssh-server
            sudo systemctl enable sshd
            sudo  systemctl status sshd

            sudo service sshd start

     

## install WSL2 (Windows Subsystem for Linux 2) on Windows 10

        https://pureinfotech.com/install-windows-subsystem-linux-2-windows-10/#install_wsl_command_1909_windows10

## Visual studio 2019 Connect to WSL

        sudo apt install g++ gdb make ninja-build rsync zip

        https://docs.microsoft.com/en-us/cpp/linux/configure-a-linux-project?view=msvc-170

In your WSL instance,
        sudo nano /etc/wsl.conf

inser with the following contents:

[user]
        default=username

from PowerShell, 

        wsl --terminate <distro name>
        
and restart WSL.