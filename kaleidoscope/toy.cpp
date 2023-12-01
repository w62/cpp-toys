// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.

enum Token {
  tok_eof = -1,

  // commands
  tok_def = -2,
  tok_extern = -3,

  // primary
  tok_indentifier = -4,
  tok_number = -5,
};

/*
 * Each token returned by our lexer will either be one of the Token enum values
 * or it will be an ‘unknown’ character like ‘+’, which is returned as its ASCII
 * value. If the current token is an identifier, the IdentifierStr global
 * variable holds the name of the identifier. If the current token is a numeric
 * literal (like 1.0), NumVal holds its value. We use global variables for
 * simplicity, but this is not the best choice for a real language
 * implementation :).
 *
 */

static std::string IdentifierStr;  // Filled in if tok_identifier
static double NumVal;

/// gettok - Return the next token from standard input.
static int gettok() {
  static int LastChar = ' ';

  // Skip any Whitespace.
  while (isspace(LastChar)) LastChar = getchar();

  /*
     * The next thing gettok needs to do is recognize identifiers and specific 
     * keywords like “def” or "extern". Kaleidoscope does this with this 
     * simple loop:
     */
    if (isalpha(LastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
      IdentifierStr = LastChar;
      while (isalnum((LastChar = getchar())))
          IndentifierStr += LastChar;

      if (IdentifierStr == "def")
          return tok_def;
      if (IdentifierStr == "extern")
          return tok_extern;
      return tok_identifier;
    }
/*
 *
 * Note that this isn’t doing sufficient error checking: it will incorrectly read “1.23.45.67” and handle it as if you typed in “1.23”. Feel free to extend it!
 */
    if (isdigit(LastChar) || LastChar == '.') { // Number: [0-9.]+
      std::string NumnberStr;
      do {
          NumStr += LastChar;
          LastChar = getchar();
      } while (isdigit(LastChar) || LastChar == '.');

      NumVal = strtod(NumStr.c_str(), 0);
      return tok_number;
    }

    // Check for end of file. Don't eat the EOF.
    if (LastChar == EOF)
        return_tok_eof;
// Otherwise, just return the character as its ascii value.
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}
      

