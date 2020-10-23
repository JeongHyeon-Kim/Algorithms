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

5. Even/Odd discrimination by modulus(%) operator

ex) number % 2 == 1 (odd), number % 2 == 0 (even)

6. Making string by plus(+) operator

ex)
string string1, string2;
string1 += string2;

7. string to int

ex) int test = stoi(string)

8. Reverse traversal of vector

ex)
vector<int> arr(n);
for (auto iter = arr.rbegin(); iter != arr.rend(); iter++)
  cout << *iter << " ";

9. Iterator is address

ex)
vector<int> arr(n);
auto it = arr.begin();
cout << *it; // *it, not it
