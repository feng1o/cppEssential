//�Ƚ�ţ�ķ����������Ҫɾ���ض��У�mmap �ķ���Ӧ���Ƿǳ��õ��ˣ���http://bbs.chinaunix.net/thread-698623-2-1.html
//��ʱ������...

/*
http://blog.sina.com.cn/s/blog_4ac1b5f60102v5al.html
���⣺
1.��������ļ��ܴ󣬻᲻����ڴ������ˣ�������
2.����Ч�ʣ�����û�и��õİ취��


//�������岿��ʡ��
file = fopen(pathname, "rb");//�򿪴����ļ���file���ļ�ָ�룬pathname�Ǵ����ļ���·�����ļ���
filedata[0] = (char *)malloc(LENGTH*sizeof(char));//filedata��ָ���������ڴ��ɾ�������ʱ���ݣ�LENGTH��ÿ���ַ�������ͬ����
//�ҳ�Ҫɾ�����ַ����������������ַ���������ʱָ������ 
for (found = 0, y = 0; fread(filedata[y], LENGTH, 1, file);)//found�����ж��Ƿ��ҵ�Ҫɾ�����ַ���
{
	*(filedata[y] + LENGTH) = '\0';
	if (found == 0)//û���ҵ�ǰ�Ž��бȽ�
	{
		if (strcmp(deldata, filedata[y]) == 0)//deldata��Ҫɾ�����ַ���
		{
			found = 1;
			//�ҵ�Ҫɾ�����ַ���������ʱ��ŵ�ָ��������ɾ�� 
			free(filedata[y]);
			y--;
		}
	}
	y++;
	filedata[y] = (char *)malloc((LENGTH + 1)*sizeof(char));
}
free(filedata[y]);//y�����1����������һ���ڴ�ռ�
fclose(file);
if (found == 0)
{
	printf("û���ҵ�Ҫɾ�����ַ�����\n");
}
else//����ɾ��ָ���ַ�����ʣ����������ݴ���ʱ��ŵ�ָ�����������±��浽�����ļ�
{
	file = fopen(pathname, "wb");
	for (m = 0; m
	{
		fwrite(filedata[m], LENGTH, 1, file);
		free(filedata[m]);//�ͷ��ڴ�
	}
	fclose(file);
}

*/