#include <leetcode.h>

struct rdx_node {
	bool end;
	struct rdx_node *next[26];
};

void free_rdx_node(struct rdx_node *node)
{
	int i;
	if (!node)
		return;
	for (i = 0; i < 26; i++)
		free_rdx_node(node->next[i]);
	free(node);
}

char* replaceWords(char** dict, int dictSize, char* sentence)
{
	int i, j, k, l, len;
	char *rwords, r[101];
	struct rdx_node *root, **node;
	root = calloc(sizeof(*root), 1);
	len = 1024;
	rwords = malloc(sizeof(*rwords) * len);
	for (i = 0; i < dictSize; i++) {
		for (j = 0, node = &root; dict[i][j]; j++) {
			node = &((*node)->next[dict[i][j] - 'a']);
			if (!(*node))
				*node = calloc(sizeof(**node), 1);
		}
		(*node)->end = true;
	}
	for (i = 0, l = 0; sentence[i]; i++) {
		if (sentence[i] == ' ') {
			rwords[l++] = sentence[i];
			if (l >= len) {
				len += 1024;
				rwords = realloc(rwords, len);
			}
			continue;
		}

		for (j = 0, k = i, node = &root;
			sentence[k] && sentence[k] != ' ';
			j++, k++) {
			node = &((*node)->next[sentence[k] - 'a']);
			if (!(*node))
				break;
			r[j] = sentence[k];
			if ((*node)->end) {
				j++;
				break;
			}
		}
		if (!j || !(*node) || !(*node)->end) {
			for (k = i;
				sentence[k] && sentence[k] != ' ';
				k++, l++) {
				rwords[l] = sentence[k];
				if (l >= len) {
					len += 1024;
					rwords = realloc(rwords, len);
				}
			}
			i = k - 1;
			continue;
		}

		while (sentence[k] && sentence[k] != ' ')
			k++;
		i = k - 1;
		for (k = 0; k < j; k++, l++) {
			rwords[l] = r[k];
			if (l >= len) {
				len += 1024;
				rwords = realloc(rwords, len);
			}
		}
	}
	free_rdx_node(root);
	rwords[l] = 0;
	return rwords;
}

void tc_0(void)
{
	char *dict[] = {"cat", "bat", "rat"};
	int dictSize = sizeof(dict)/sizeof(*dict);
	char sentence[] = "the cattle was rattled by the battery";
	char *rwords = replaceWords(dict, dictSize, sentence);
	printf("the cat was rat by the bat\n%s\n\n", rwords);
	free(rwords);
}

void tc_1(void)
{
	char *dict[] = {"gymth","qglnp","hmgs","rsz","upq","aq","relo","hz","i","atwlc","d","cxax","ymy","hfvr","x","qzgxa","abdgp","dwksr","p","yf","qao","von","bpji","mzxky","tuabq","yquz","j","dzpju","hadfd","svux","rmyku","ae","cr","bowu","slak","s","qvlg","geuw","qx","t","vzix","ycl","xoeyd","cq","jhjm","lt","uye","hwe","rtidu","ksy","dnl","knlsv","yv","ndga","ounoa","kah","dlruh","wbg","vfzt","unnh","kpd","uutv","vxz","lwmh","skyw","f","tktpf","botu","rrs","zdlr","papga","xeyn","z","tqjh","ivzh","b","k","woyl","ixas","tiyd","g","lcq","ta","xd","ztg","oxk","ax","hgqm","dx","zri","heeq","m","q","ub","xxo"};
	int dictSize = sizeof(dict)/sizeof(*dict);
	char sentence[] = "snhaafs hprzyepsgezd ntc ktogne kluwleaobb nwjatqwpx tzobvpylft s jzrlxuzsw fkkjvorqnhpeoikjepmm rxerxpfjssfvtzvunri rpnaizunsjlppuzppf udoqhtcpcv rtegaohvotz eovfuvymmzywjoytegf cztodouflfgc qtom vlyyboks izzhgin rtnrxmm ovtgafmvzu xxeabovlxmy zrqzsexkerfjiqkyjou ygelavmpdncapreadba y kedhgamqyjaffbex fosrpjojgwzjfaoxn pjqysu esaaoksfsvjabdbk e sknkvxxngqpfdkm dmqfzqjuunrbdmkjp fesdkqewhigg anlrixkeqaexh yhmywgpebtsprje tmwbuqnffycjm otfnqgtetdi ovyrmzo vkeze opq rijfryopiizsitum jyz ynoworq xmqohxpgce eblgjvghxxndaqvknph ghhxzfda onukxgjtdrjmoddqhfl xwmutmcvrzkjzxmtz xslacnagnrlu nidcqwrffyrlosnjjl stwperkfcvyzezbebktq fjhb hhxeturoihcdgkkq evzcmxhrnwvnpbbfsm cshlxs qouyuxwdjwyhfp ceiddqqfp pzbsuxqc qgrbisfcnyhdwmbkdjh cxlxqwi z ihgekczvavdwvivvj fjttwiqxqjgakd diggghnustrtizokcrw earkadvle eufogeidbfrcz cnms gomw rbraz bsbopklfbnbbzcod zbayalermeyxn ckrfpylus ofmpofltxmsideqxx rmkqaxda map gvpqwuofuwue o mkzz njrqnwlihegmpmr dbbpwy t c apljlybekb avgxnubzswldzyln tkxwrskwqkzdueuautg cekskcpocbubavun jezsixdu yepzrfdrhqajotjohmzo fleesmkehkvoj ciloebxldjgwtf ruzc tshzh cgudcyfzppgduvfha grcrveutgkz cfsrzt";
	char *rwords = replaceWords(dict, dictSize, sentence);
	printf("s hprzyepsgezd ntc k k nwjatqwpx t s j f rxerxpfjssfvtzvunri rpnaizunsjlppuzppf udoqhtcpcv rtegaohvotz eovfuvymmzywjoytegf cztodouflfgc q vlyyboks i rtnrxmm ovtgafmvzu x z ygelavmpdncapreadba y k f p esaaoksfsvjabdbk e s d f anlrixkeqaexh yhmywgpebtsprje t otfnqgtetdi ovyrmzo vkeze opq rijfryopiizsitum j ynoworq x eblgjvghxxndaqvknph g onukxgjtdrjmoddqhfl x x nidcqwrffyrlosnjjl s f hhxeturoihcdgkkq evzcmxhrnwvnpbbfsm cshlxs q ceiddqqfp p q cxlxqwi z i f d earkadvle eufogeidbfrcz cnms g rbraz b z ckrfpylus ofmpofltxmsideqxx rmkqaxda m g o m njrqnwlihegmpmr d t c apljlybekb avgxnubzswldzyln t cekskcpocbubavun j yepzrfdrhqajotjohmzo f ciloebxldjgwtf ruzc t cgudcyfzppgduvfha g cfsrzt\n");
	printf("%s\n\n", rwords);
	free(rwords);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

