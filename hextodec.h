
quint64 hexToDec(const QByteArray &hex)
{
  quint64 result = 0; quint64 position = 0;
  char atPos;
  for(quint64 i=hex.size(); i; i--)
  {
    atPos = hex.at(i-1);
    switch(atPos)
    {
      case '0':
	break;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':	
      {
	result+=pow(16,position)* atoi(&atPos);
	break;
      }
      case 'A':
      case 'a':
      {
	result += pow(16,position)* 10;
	break;
      }
      case 'B':
      case 'b':
      {
	result += pow(16,position)* 11;
	break;
      }
      case 'C':
      case 'c':
      {
	result += pow(16,position)* 12;
	break;
      }
      case 'D':
      case 'd':
      {
	result += pow(16,position)* 13;
	break;
      }
      case 'E':
      case 'e':
      {
	result += pow(16,position)* 14;
	break;
      }
      case 'F':
      case 'f':
      {
	result += pow(16,position)* 15;
	break;
      }
      default:
	return 0;
    }
    position++;
  }
  return result;
}