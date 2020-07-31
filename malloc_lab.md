# malloc lab

- 这个lab要求设计一个虚拟内存分配器

- 要看完csapp的第九章

- 针对书上给出的可以设计出很多种组织空闲内存的方式

- 我选择了显式空闲链表，因为之前读过ptmalloc源码

- 首先设计好helper function

  - insert_node

  - 将结点插入对应size的free_list

  - delete_node

  - 从对应size的free_list移除结点

  - coalesce

  - 针对内存中相邻的chunk是否都是空闲的来合并，阻止外部内存碎片

  - place

  - 对于分配出的chunk，如果size比需求的size要大，该如何切割来防止内存碎片

    - 我看到有个人的blog针对这个做了优化大概是
      - 比较小的chunk就从头部开始切割
      - 比较大的chunk就从尾部开始切割

    - 但是ptmalloc里好像没有针对性的优化，我也就没写

  - extend_heap

    - 当堆里的内存不够了，就要用sbrk扩展堆

- malloc
  - 没什么好说的，针对size去搜索对应的free_list，如果没有就去更大size的free_list去搜索
  - 如果没找到就扩展堆，然后从新扩展的区域进行分配

- free
  - 插入对应的free_list
  - 然后合并物理相邻的空闲堆块

- realloc
  - 查看realloc的size是否<=当前chunk的size，如果<=，就直接返回
  - 如果大于就用过malloc申请一个新的chunk，然后释放原chunk