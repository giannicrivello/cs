# cs
repo for all projects done in class 

hopPass
--------------------
Dev enviornment:
machine: MacbookPro 2020
chip: M1
OS: macOS Monterey

- crappy program I worte to model a payment system through cli. Good exposure to the joys of c++ linking multiple files.
- I wanted to gain some exposure with a trivial build process (getting experience with building a .h file and static linking that file with its corresponmding implementation .o file
then finally linking for the final binary.)
- rule of thumb...
      <filename>.h <filename.h_implementation>.cpp -> (you can think of this as a headerfile bundle)
      [add the .h file to the <filename.h_implementation>.cpp using #include directive]
  
  now you have a super simple library of sorts a declaration of what you want and the actual implementation.
  you can use this in your main file as such.
      <main>.cpp
      [add the .h file to the <main>.cpp using #include directive]
   
  compile to object files <mainProgram>.cpp <filename.h_implementation.cpp>
      g++ -c -std=c++11 -stdlib=libc++ <filename.h_implementation>.cpp <mainProgram>.cpp -lstdc++
      [as far as I know, these files do not need to be in a certain order. This command simply builds object files]
 
   
   compile both of these programs together to produce the main binary
        g++ <mainProgram>.o <filename.h_implementation>.o
        [as far as I know, these files do not need to be in a certain order. This command simply builds a binary from multiple files]
        
 - Errors I worked through:
        - c++ is kinda a mess. So you really need to make sure that you are linking to the right -std & -stdlib. It's not really obvious and the liteature is dense.
        when compiling the program, what worked for me was the above process.
        - ld: symbol(s) not found for architecture arm64 was an error log I ran into alot. What this basically means is that your compiler doesnt know where a 
        complex data structure you are reffering to is (typically due to the fact you are linking/referening files wrong). For me, this was mainly spelling errors.
            
- What next?
            - covering more of the edgecases (this was built in an evening before it was due so obviously there are hole)
            - Creating a menu class to further abstract the APIs from the main program
            - Create a UI (IamGUI or some other library)
            - Further generalize library APIs
       
RockChallenge
