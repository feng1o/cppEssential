//比较牛的方法：如果是要删除特定行，mmap 的方法应该是非常好的了：）http://bbs.chinaunix.net/thread-698623-2-1.html
//有时间试试...

/*
http://blog.sina.com.cn/s/blog_4ac1b5f60102v5al.html
问题：
1.这样如果文件很大，会不会把内存塞满了？？？？
2.这样效率，，有没有更好的办法？


//变量定义部分省略
file = fopen(pathname, "rb");//打开磁盘文件，file是文件指针，pathname是磁盘文件的路径和文件名
filedata[0] = (char *)malloc(LENGTH*sizeof(char));//filedata是指针数组用于存放删除后的临时数据，LENGTH是每个字符串的相同长度
//找出要删除的字符串，并将其它的字符串存入临时指针数组 
for (found = 0, y = 0; fread(filedata[y], LENGTH, 1, file);)//found用于判断是否找到要删除的字符串
{
	*(filedata[y] + LENGTH) = '\0';
	if (found == 0)//没有找到前才进行比较
	{
		if (strcmp(deldata, filedata[y]) == 0)//deldata是要删除的字符串
		{
			found = 1;
			//找到要删除的字符串，从临时存放的指针数组中删除 
			free(filedata[y]);
			y--;
		}
	}
	y++;
	filedata[y] = (char *)malloc((LENGTH + 1)*sizeof(char));
}
free(filedata[y]);//y多加了1，多申请了一段内存空间
fclose(file);
if (found == 0)
{
	printf("没有找到要删除的字符串。\n");
}
else//将已删除指定字符串后剩余的所有数据从临时存放的指针数组中重新保存到磁盘文件
{
	file = fopen(pathname, "wb");
	for (m = 0; m
	{
		fwrite(filedata[m], LENGTH, 1, file);
		free(filedata[m]);//释放内存
	}
	fclose(file);
}

*/