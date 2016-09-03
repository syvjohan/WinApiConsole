#ifndef KEYBOARD_H
#define KEYBOARD_H

char
KeyboardCharInput( WPARAM wParam ) {
	char retChar = '.';
	switch ( wParam ) {
		case 0x41:
		{
			retChar = 'A';
			break;
		}

		case 0x42:
		{
			retChar = 'B';
			break;
		}

		case 0x43:
		{
			retChar = 'C';
			break;
		}

		case 0x44:
		{
			retChar = 'D';
			break;
		}

		case 0x45:
		{
			retChar = 'E';
			break;
		}

		case 0x46:
		{
			retChar = 'F';
			break;
		}

		case 0x47:
		{
			retChar = 'G';
			break;
		}

		case 0x48:
		{
			retChar = 'H';
			break;
		}

		case 0x49:
		{
			retChar = 'I';
			break;
		}

		case 0x4A:
		{
			retChar = 'J';
			break;
		}

		case 0x4B:
		{
			retChar = 'K';
			break;
		}

		case 0x4C:
		{
			retChar = 'L';
			break;
		}

		case 0x4D:
		{
			retChar = 'M';
			break;
		}

		case 0x4E:
		{
			retChar = 'N';
			break;
		}

		case 0x4F:
		{
			retChar = 'O';
			break;
		}

		case 0x50:
		{
			retChar = 'P';
			break;
		}

		case 0x51:
		{
			retChar = 'Q';
			break;
		}

		case 0x52:
		{
			retChar = 'R';
			break;
		}

		case 0x53:
		{
			retChar = 'S';
			break;
		}

		case 0x54:
		{
			retChar = 'T';
			break;
		}

		case 0x55:
		{
			retChar = 'U';
			break;
		}

		case 0x56:
		{
			retChar = 'V';
			break;
		}

		case 0x57:
		{
			retChar = 'W';
			break;
		}

		case 0x58:
		{
			retChar = 'X';
			break;
		}

		case 0x59:
		{
			retChar = 'Y';
			break;
		}

		case 0x5A:
		{
			retChar = 'Z';
			break;
		}

		case 0x61:
		{
			retChar = 'a';
			break;
		}

		case 0x62:
		{
			retChar = 'b';
			break;
		}

		case 0x63:
		{
			retChar = 'c';
			break;
		}

		case 0x64:
		{
			retChar = 'd';
			break;
		}

		case 0x65:
		{
			retChar = 'e';
			break;
		}

		case 0x66:
		{
			retChar = 'f';
			break;
		}

		case 0x67:
		{
			retChar = 'g';
			break;
		}

		case 0x68:
		{
			retChar = 'h';
			break;
		}

		case 0x69:
		{
			retChar = 'i';
			break;
		}

		case 0x6A:
		{
			retChar = 'j';
			break;
		}

		case 0x6B:
		{
			retChar = 'k';
			break;
		}

		case 0x6C:
		{
			retChar = 'l';
			break;
		}

		case 0x6D:
		{
			retChar = 'm';
			break;
		}

		case 0x6E:
		{
			retChar = 'n';
			break;
		}

		case 0x6F:
		{
			retChar = 'o';
			break;
		}

		case 0x70:
		{
			retChar = 'p';
			break;
		}

		case 0x71:
		{
			retChar = 'q';
			break;
		}

		case 0x72:
		{
			retChar = 'r';
			break;
		}

		case 0x73:
		{
			retChar = 's';
			break;
		}

		case 0x74:
		{
			retChar = 't';
			break;
		}

		case 0x75:
		{
			retChar = 'u';
			break;
		}

		case 0x76:
		{
			retChar = 'v';
			break;
		}

		case 0x77:
		{
			retChar = 'w';
			break;
		}

		case 0x78:
		{
			retChar = 'x';
			break;
		}

		case 0x79:
		{
			retChar = 'y';
			break;
		}

		case 0x7A:
		{
			retChar = 'z';
			break;
		}
	}

	return retChar;
}

void
KeyboardVKInput( WPARAM wParam ) {
	switch ( wParam ) {
		case VK_RETURN:
		{

			break;
		}

		case VK_SPACE:
		{

			break;
		}

		case VK_BACK:
		{

			break;
		}
	}
}

#endif //!KEYBOARD_H