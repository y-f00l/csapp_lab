# arch lab

## partA

- 这部分就是单纯用y86架构的汇编去编写程序
- 没什么好说的，书上给过一个示例程序，可以对照格式写
- 1.迭代计算链表数据域的和 sum.ys
- 2.递归计算链表数据域的和 rsum.ys
- 3.实现一个copy函数，从src block拷贝到dest block
- 这部分整体不难，照着example.c里的source code写，注意一下语法就好
- 递归应该把原寄存器的值保存一下
- 代码在虚拟机上，我mac上的虚拟机vmware tools有问题，没法传文件，代码先不传了

## partB

- 去给cpu添加iaddq指令
- hint:P254给了iaddq指令的内存表示
- 指导书里写了去参考irmovq指令和OPq指令，参考后iaddq指令总结如下
- 取指:
  - icode:ifun <- M[PC]
  - rA:rB <- M[PC+1]
  - valC <- M[PC+2]
  - valP <- PC + 10       //立即数占了8字节
- 译码:
  - valB <- R[rB]
- 执行:
  - valE <- valB + valC
- 写回:
  - R[rB] <- valE
- 更新:
  - PC <- valP
- 完事具备，接下来就是去理解sim/seq/seq-full.hcl这个文件
- 根据注释发现很好懂，就是描述各个指令执行过程中的特征比如
  - 是否需要寄存器
  - 是否需要立即数
  - and so on
- 把具有相同特征的指令放到一个“集合”里
- 按照上面分析的去添加代码就好了，源代码里很贴心的定义好了iaddq指令
- 因为这个指令一定是合法的，所以instr_valid里要添加
- 因为需要寄存器，所以need_regids里要添加
- 因为需要常数，所以need_valC要添加
- 因为rB作为src，所以要在srcB里添加(别问为什么是B，去看P254)
- 因为要把结果写回到rB，所以destE里的rB分支要添加
- 常数作为varC出现，所以在aluA的valC分支中添加
- 寄存器作为varB出现，所以在aluB的valB分支中添加
- 因为OPq指令都会影响标志寄存器，所以要要在set_cc中添加
   
