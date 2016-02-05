Date: 2016-02-05
Author: Frans Lundberg, ASSA ABLOY AB


Project specification
=====================

This document describes a development project to create software
to convert an array of bytes to a Binson representation and a Binson
representation to an array of bytes. The implementation does not build
an in-memory representation of Binson object. It is more of a streaming library
similar to SAX for XML (instead of DOM).

Project information, scope, requirements:

* Project name: binson-c-light
* Writer: Conversion Binson fields -> byte array must be supported.
* Parser: Conversion byte array -> stream of Binson fields must be supported.
* The writer does not have be "validating". It should be easy to 
  generate valid Binson bytes with the writer, but it may be possible
  to generate invalid Binson bytes too.
* Similarly, the parser does not necessarily have to be able to detect whether 
  the input is valid or not for every possible input.
* The project is similar in scope to the [binson-java-light project](https://github.com/franslundberg/binson-java-light) 
  on Github.
* No dynamic memory allocation while serializing / deserializing is allowed.
* A goal is to keep binson-light.c within 1500 lines of code. binson-java-light is around 600 lines.
* UTF-8 does not need to be handled "explicitely". Assuming US-ASCII for
  string literals is OK. It must however be possible to match field names using raw UTF-8 bytes
  and use raw UTF-8 bytes when serializing.
* Deliverables, the following files (filenames may be changed if appropriate):
     - binson_light.c           // source code
     - binson_light.h           // header file
     - README.md                // information
     - binson_light_test.c      // main method with some tests
     - binson_light_examples.c  // example code
* No dependencies on libraries beyond C lib.
* The library binson-c-light is used by including
  the C-source (binson_light.c, binson_light.h) directly in the application project.
* The C code is designed for small devices. It should work on Arduino Nano.
* There are natural limitations on the Arduino Nano, for example int64_t is
  not supported, so on Arduino Nano, support for 64-bit integer 
  (and 64-bit float, I guess) is not required.
* The source should build with simple GCC commands described in README.md. No build framework or
  test framework should be used.
* The software should run on Arduino Nano.
* The software should build and run on Linux Ubuntu + GCC.
* High code quality is important.
* The code should follow the field ordering notes below in this document.
* See the "Byte array size" section.
* See the "Error handling" section.

Feel free to discuss the requirements; they will likely evolve during the project.

The project is divided into three phases.

* Phase 1: first implementation. A complete implementation. First test on Arduino Nano.
* Phase 2: refactoring of Phase 1 code after discussions with Frans Lundberg. More testing.
* Phase 3: one month of support (fixing bugs, answering questions) after Phase 2 
  has been completed.
  
Field ordering
--------------

The ordering of Binson fields is the responsibility of the application developer.

Serializer: The serializer should raise an error condition if the application 
developer tries to use a bad ordering of the fields. Parser: The parser can assume 
the fields are ordered correctly and does not need to check for this.

To reduce code size and complexity, field order checks by the serialize could be 
omitted if needed.

Byte array size
---------------

When a Binson object is serialized to a byte array, there is the issue of array
size. The resulting length in bytes is typically not known in advance.
The binson-c-light serializer should check that is it not writing beond the
boundary of the array.

The application code should be able to do the following (just to demonstrate
the feature; code does not suggest any specific naming approach etc):

    binson_writer* w;
    binson_writer_init(w, buffer, buffer_size);
    
    binson_write_begin(w);
    binson_write_integer_field(w, "myInteger", 12345);
    ...
    binson_write_end(w);
    
    /* 
    Here, the application can check w for errors. Furthermore 
    "w->size" or similar should contain the result size
    even in cases when the buffer_size was exceeded! Writer should be 
    able to continue somehow not actually writing to buffer, but counting 
    the result size. This allows the application to increase
    buffer size and run the code again. This time the size is known in advance.
    */
    
Error handling
--------------

The application code uses the library to serialize or deserialize using 
potentially many function calls. For example:

    binson_writer* w;
    binson_writer_init(w, buffer, buffer_size);
    
    binson_write_begin(w);
    binson_write_integer_field(w, "myInteger", 12345);
    ...
    binson_write_end(w);
    
It should be possible for the application code to check for errors *once*
after a serialization (or deserialization). Checking for errors after every line
of code is cumbersome and makes the code harder to read. This is likely implemented
by checking "w.error" is similar for every binson_writer_x function (for the serialization
case):

    void binson_write_integer_field(binson_writer* w, ...) 
    {
        if (w.error) return;
        // actual function implementation...
    }

The example code is used just to demonstrate the idea.

