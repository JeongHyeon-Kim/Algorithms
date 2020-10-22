1. Read a full line of input from stdin (cin) and save it to our variable, input_string.

ex) getline(cin, input_string);

2. To consume the whitespace or newline between the end of a token and the beginning of the next line

ex) getline(cin >> ws, s_s); // eat whitespace, extract whitespaces

3. Wanted to scale this to 1 decimal places

ex) cout << fixed << setprecision(1) << pi << endl;

4. Line ignores the rest of the current line, up to 'n' or EOF

cin.ignore({number of characters to ignore}, {delimiter});

numberic_limits<streamsize>::max() : maximum number of characters

ex) cin.ignore(numeric_limits<streamsize>::max(), '\n');
