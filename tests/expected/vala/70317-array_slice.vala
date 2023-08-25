public static int main()
{
	int[] b = { 2, 4, 6, 8 };

	// Simple slicing.
	var c = b[1:3];
	var d = b[1:3];
	var e = b[1 :3];
	var f = b[1 :3];
	var g = b[1  :3];

	// Slicing inside ternary operator.
	var h = true ? b : b[1:3];

	return 0;
}
