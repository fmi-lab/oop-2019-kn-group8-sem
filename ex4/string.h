#ifndef _H_STRING
#define _H_STRING

/*! Strings are objects that represent sequences of characters.

The string class provides support for such objects with an interface similar to that of a standard array
of bytes, but adding features specifically designed to operate with strings of single-byte characters.

Multi-byte characters (e.g UTF-16) or variable-byte characters(e.g UTF-8) are not supported.
*/
class String {

private:  // private members
    int size;
    char *buffer;

private: // private functions - helper functions used during implementation


public: // public functions. This is the interface of the class. The contract between the class and its users
    
    String();
    String(char ch, int repetitions);
    String(const char * cstr);
    // copy constructor
    String(const String& old_str);
    // desctructor
    ~String();

    /*!
        Assigns a new value to the string, replacing its current contents.
    */
    String& operator= (const String& str);
    
    /*! Returns a reference to the character at position index in the string.
        \param index Value with the position of a character within the string.
                     Note: The first character in a string is denoted by a value of 0 (not 1).
    */
    char& operator[] (int index);
    const char& operator[] (int index) const;


    /*! Returns the length of the string, in terms of bytes.
        This is the number of actual bytes that conform the contents of the string, 
        which is not necessarily equal to its storage capacity.
    */
    int length() const;

    /*! 
        Searches the string for the first occurrence of the specified character  
    */
    int findIndexOf(char c) const;

    /*! 
        Inserts additional characters into the string right before the character indicated by pos
        \param index Value with the position of a character within the string.
        \param c the character being inserted
    */
    void insert(int index, char c);

    /*! 
        Erases the portion of the string value that begins at the character position index and spans len characters        
        \param index Position of the first character to be erased.
        \param len Number of characters to erase
    */
    void erase(int index, int len = 1);

    /*!
        Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string)
         representing the current value of the string object.
    */
    const char* c_string() const;
};

String& operator+(String s, char c);
String& operator+(char c, String s);


#endif
