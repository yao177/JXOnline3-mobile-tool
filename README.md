# JXOnline3-mobile-tool
## 剑网3指尖江湖手游查询工具

### 食谱查询
- food
  - `cd 食谱查询` 到目录下
  - `g++ -o food food.cpp -std=c++11 -stdlib=libc++ -fno-use-cxa-atexit` 进行编译
  - `./food` 运行
  - 输入背包里有的食材 + `#`
  - Enter回车 -> 进行查询
- formula
  - `cd 食谱查询` 到目录下
  - `g++ -o formula formula.cpp -std=c++11 -stdlib=libc++ -fno-use-cxa-atexit`
  - `./formula` 运行
  - 输入菜品名 + 现有的食材 + `#`
  - Enter回车 -> 进行查询

### 江湖物产
- resource
  - `cd 江湖物产` 到目录下
  - `g++ -o resource resource.cpp -std=c++11 -stdlib=libc++ -fno-use-cxa-atexit` 进行编译
  - `./resource` 运行
  - 输入需要查询的物产 / 材料 + `1`按数量排序 / `2`按优先级排序
  - Enter回车 -> 进行查询
