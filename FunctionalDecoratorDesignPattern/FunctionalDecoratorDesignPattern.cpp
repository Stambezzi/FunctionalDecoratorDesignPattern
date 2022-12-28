#include <iostream>
#include <functional>

template <typename> class Logger;

template <typename R, typename... Args>
class Logger<R( Args... )>
{
public:
    Logger( const std::string& name, const std::function<R(Args...)>& func ) : fFuncName( name ), fFunc( func ) {};

    R operator() ( Args ...args )
    {
        std::cout << "Entering " << fFuncName << std::endl;
        R result = fFunc( args... );
        std::cout << "Result = " << result << std::endl;
        std::cout << "Exiting " << fFuncName << std::endl;
        return result;
    }

private:
    std::function<R( Args... )> fFunc;
    std::string fFuncName;
};

int Sum( int a, int b )
{
    return a + b;
}

std::string Concatenate( const std::string& first, const std::string& second )
{
    return first + " " + second;
}

//int Sum( int a )
//{
//    return a;
//}
//
//template <typename... Args>
//int Sum( int a, Args... args )
//{
//    return a + Sum( args... );
//}

template <typename... Args>
void log()
{
    //std::cout<<sum( 5, 10, 3, 4, 7, 2, 1 );
    //Logger<int( Args... )> sumLogger( "Sum of two diggits", Sum );
    //int result = sumLogger( std::bind(1, 2)); //3, 4, 7, 2, 1 );

    Logger<int( int, int )> sumLogger( "Sum of two diggits", Sum );
    int result = sumLogger( 1, 2 );  

    std::cout << std::endl;

    Logger<std::string( const std::string& first, const std::string& second )> concatLogger( "Concatenation", Concatenate );
    std::string resultStr = concatLogger( "edno", "dve" );
}

int main()
{
    log();
}