#define bool int
#define true 1
#define false 0

bool canConstruct(char* ransomNote, char* magazine)
{
	int count[256] = {0};

	while (*magazine) count[*magazine++]++;
	while (*ransomNote) {
		count[*ransomNote]--;
		if (count[*ransomNote] < 0)
			return false;
		ransomNote++;
	}
	return true;
}

