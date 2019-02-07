int x, *ptr = nullptr;
ptr = &x;
ptr = 100; // There should be * before ptr
cout << x << endl;
