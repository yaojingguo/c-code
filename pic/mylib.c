int my_func(int no) {
	static int offset = 0;
	offset++;
	return no + offset;
}
