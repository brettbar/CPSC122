int userInput()
{
	int jars;
	cout << "Enter number of jars";
	cin >> jars;
	if (jars >= 0)
	{
		return jars;
	}
	else 
	{
		return userInput();
	}
}

