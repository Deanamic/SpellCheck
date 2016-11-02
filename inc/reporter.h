#ifndef INC_SCHECK_REPORTER_H
#define INC_SCHECK_REPORTER_H

#include <iostream>
#include <string>

/* THis is an abstract base clas, cannot be craeted
only derived from */
class Reporter {
    public:
        Reporter( std::ostream & os ) : mOut( os ) {
        }
        virtual ~Reporter() {
        }
        /* VIRTUAL means the will act polymorphically
        =0 will make it act as pure which means that
        derived classes must provide implementations*/
        virtual void ReportHeader() = 0;
        virtual void ReportError( const std::string & word,
                                  const std::string & context,
                                  unsigned int line,
                                  const std::string & filename ) = 0;
        virtual void ReportFooter() = 0;

    /*protected can only be accesed from the class that defines it
    and from any class that inherits it */
    protected:

        std::ostream & Out() {
                return mOut;
        }
    private:
        std::ostream & mOut;
};

#endif
