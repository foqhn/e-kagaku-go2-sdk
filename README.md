# unitree_sdk2
Unitree robot sdk version 2.

### Prebuild environment
* OS  (Ubuntu 20.04 LTS)  
* CPU  (aarch64 and x86_64)   
* Compiler  (gcc version 9.4.0) 

### Installation
```bash
sudo ./install.sh

```

### Build examples
最初に以下のコマンドを実行すること
プログラムを修正した時には、ビルドをし直すこと
```bash
mkdir build
cd build
cmake ..
make
```

### 新しくプログラムを作成する場合
e-kagaku-go2-sdk/CMakeList.txtに以下を追記　(エントリーポイント)
```bash
add_executable(実行名 path/to/file/プログラム名.cpp)
```
例
```bash
add_executable(sample_project1 myproject/sample_project1.cpp)
```

### Notice
For more reference information, please go to [Unitree Document Center](https://support.unitree.com/home/zh/developer).
