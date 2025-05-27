bool isPalindrome( int x ) 
{
    char xParaString[12];
    sprintf( xParaString, "%d", x );
    int stringLen = strlen( xParaString );
    int k = stringLen - 1;
    
    for( int i = 0; i < stringLen; i++ )
    {
        if( xParaString[k--] != xParaString[i] )
        {
            return false;
        }
    }
    return true;
}