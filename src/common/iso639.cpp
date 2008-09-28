/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   $Id$

   ISO639 language definitions, lookup functions

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#include <stdio.h>
#include <string.h>

#include "common.h"
#include "iso639.h"

const iso639_language_t iso639_languages[] =
  {{"Abkhazian", "abk", "ab", NULL},
   {"Achinese", "ace", NULL, NULL},
   {"Acoli", "ach", NULL, NULL},
   {"Adangme", "ada", NULL, NULL},
   {"Afar", "aar", "aa", NULL},
   {"Afrihili", "afh", NULL, NULL},
   {"Afrikaans", "afr", "af", NULL},
   {"Afro-Asiatic (Other)", "afa", NULL, NULL},
   {"Akan", "aka", "ak", NULL},
   {"Akkadian", "akk", NULL, NULL},
   {"Albanian", "alb", "sq", "sqi"},
   {"Aleut", "ale", NULL, NULL},
   {"Algonquian languages", "alg", NULL, NULL},
   {"Altaic (Other)", "tut", NULL, NULL},
   {"Amharic", "amh", "am", NULL},
   {"Apache languages", "apa", NULL, NULL},
   {"Arabic", "ara", "ar", NULL},
   {"Aragonese", "arg", "an", NULL},
   {"Aramaic", "arc", NULL, NULL},
   {"Arapaho", "arp", NULL, NULL},
   {"Araucanian", "arn", NULL, NULL},
   {"Arawak", "arw", NULL, NULL},
   {"Armenian", "arm", "hy", "hye"},
   {"Artificial (Other)", "art", NULL, NULL},
   {"Assamese", "asm", "as", NULL},
   {"Asturian; Bable", "ast", NULL, NULL},
   {"Athapascan languages", "ath", NULL, NULL},
   {"Australian languages", "aus", NULL, NULL},
   {"Austronesian (Other)", "map", NULL, NULL},
   {"Avaric", "ava", "av", NULL},
   {"Avestan", "ave", "ae", NULL},
   {"Awadhi", "awa", NULL, NULL},
   {"Aymara", "aym", "ay", NULL},
   {"Azerbaijani", "aze", "az", NULL},
   {"Bable; Asturian", "ast", NULL, NULL},
   {"Balinese", "ban", NULL, NULL},
   {"Baltic (Other)", "bat", NULL, NULL},
   {"Baluchi", "bal", NULL, NULL},
   {"Bambara", "bam", "bm", NULL},
   {"Bamileke languages", "bai", NULL, NULL},
   {"Banda", "bad", NULL, NULL},
   {"Bantu (Other)", "bnt", NULL, NULL},
   {"Basa", "bas", NULL, NULL},
   {"Bashkir", "bak", "ba", NULL},
   {"Basque", "baq", "eu", "eus"},
   {"Batak (Indonesia)", "btk", NULL, NULL},
   {"Beja", "bej", NULL, NULL},
   {"Belarusian", "bel", "be", NULL},
   {"Bemba", "bem", NULL, NULL},
   {"Bengali", "ben", "bn", NULL},
   {"Berber (Other)", "ber", NULL, NULL},
   {"Bhojpuri", "bho", NULL, NULL},
   {"Bihari", "bih", "bh", NULL},
   {"Bikol", "bik", NULL, NULL},
   {"Bini", "bin", NULL, NULL},
   {"Bislama", "bis", "bi", NULL},
   {"Bokmål, Norwegian; Norwegian Bokmål", "nob", "nb", NULL},
   {"Bosnian", "bos", "bs", NULL},
   {"Braj", "bra", NULL, NULL},
   {"Breton", "bre", "br", NULL},
   {"Buginese", "bug", NULL, NULL},
   {"Bulgarian", "bul", "bg", NULL},
   {"Buriat", "bua", NULL, NULL},
   {"Burmese", "bur", "my", "mya"},
   {"Caddo", "cad", NULL, NULL},
   {"Carib", "car", NULL, NULL},
   {"Castilian", "spa", "es", NULL},
   {"Catalan", "cat", "ca", NULL},
   {"Caucasian (Other)", "cau", NULL, NULL},
   {"Cebuano", "ceb", NULL, NULL},
   {"Celtic (Other)", "cel", NULL, NULL},
   {"Central American Indian (Other)", "cai", NULL, NULL},
   {"Chagatai", "chg", NULL, NULL},
   {"Chamic languages", "cmc", NULL, NULL},
   {"Chamorro", "cha", "ch", NULL},
   {"Chechen", "che", "ce", NULL},
   {"Cherokee", "chr", NULL, NULL},
   {"Chewa; Chichewa; Nyanja", "nya", "ny", NULL},
   {"Cheyenne", "chy", NULL, NULL},
   {"Chibcha", "chb", NULL, NULL},
   {"Chichewa; Chewa; Nyanja", "nya", "ny", NULL},
   {"Chinese", "chi", "zh", "zho"},
   {"Chinook jargon", "chn", NULL, NULL},
   {"Chipewyan", "chp", NULL, NULL},
   {"Choctaw", "cho", NULL, NULL},
   {"Chuang; Zhuang", "zha", "za", NULL},
   {"Church Slavic; Old Church Slavonic", "chu", "cu", NULL},
   {"Old Church Slavonic; Old Slavonic; ", "chu", "cu", NULL},
   {"Church Slavonic; Old Bulgarian; Church Slavic;", "chu", "cu", NULL},
   {"Old Slavonic; Church Slavonic; Old Bulgarian;", "chu", "cu", NULL},
   {"Church Slavic; Old Church Slavonic", "chu", "cu", NULL},
   {"Chuukese", "chk", NULL, NULL},
   {"Chuvash", "chv", "cv", NULL},
   {"Coptic", "cop", NULL, NULL},
   {"Cornish", "cor", "kw", NULL},
   {"Corsican", "cos", "co", NULL},
   {"Cree", "cre", "cr", NULL},
   {"Creek", "mus", NULL, NULL},
   {"Creoles and pidgins (Other)", "crp", NULL, NULL},
   {"Creoles and pidgins,", "cpe", NULL, NULL},
   //   {"English-based (Other)", NULL, NULL, NULL},
   {"Creoles and pidgins,", "cpf", NULL, NULL},
   //   {"French-based (Other)", NULL, NULL, NULL},
   {"Creoles and pidgins,", "cpp", NULL, NULL},
   //   {"Portuguese-based (Other)", NULL, NULL, NULL},
   {"Croatian; Hrvatske", "scr", "hr", "hrv"},
   {"Cushitic (Other)", "cus", NULL, NULL},
   {"Czech", "cze", "cs", "ces"},
   {"Dakota", "dak", NULL, NULL},
   {"Danish", "dan", "da", NULL},
   {"Dargwa", "dar", NULL, NULL},
   {"Dayak", "day", NULL, NULL},
   {"Delaware", "del", NULL, NULL},
   {"Dinka", "din", NULL, NULL},
   {"Divehi", "div", "dv", NULL},
   {"Dogri", "doi", NULL, NULL},
   {"Dogrib", "dgr", NULL, NULL},
   {"Dravidian (Other)", "dra", NULL, NULL},
   {"Duala", "dua", NULL, NULL},
   {"Dutch; Flemish", "dut", "nl", "nld"},
   {"Dutch, Middle (ca. 1050-1350)", "dum", NULL, NULL},
   {"Dyula", "dyu", NULL, NULL},
   {"Dzongkha", "dzo", "dz", NULL},
   {"Efik", "efi", NULL, NULL},
   {"Egyptian (Ancient)", "egy", NULL, NULL},
   {"Ekajuk", "eka", NULL, NULL},
   {"Elamite", "elx", NULL, NULL},
   {"English", "eng", "en", NULL},
   {"English, Middle (1100-1500)", "enm", NULL, NULL},
   {"English, Old (ca.450-1100)", "ang", NULL, NULL},
   {"Esperanto", "epo", "eo", NULL},
   {"Estonian", "est", "et", NULL},
   {"Ewe", "ewe", "ee", NULL},
   {"Ewondo", "ewo", NULL, NULL},
   {"Fang", "fan", NULL, NULL},
   {"Fanti", "fat", NULL, NULL},
   {"Faroese", "fao", "fo", NULL},
   {"Fijian", "fij", "fj", NULL},
   {"Finnish", "fin", "fi", NULL},
   {"Finno-Ugrian (Other)", "fiu", NULL, NULL},
   {"Fon", "fon", NULL, NULL},
   {"French", "fre", "fr", "fra"},
   {"French, Middle (ca.1400-1600)", "frm", NULL, NULL},
   {"French, Old (842-ca.1400)", "fro", NULL, NULL},
   {"Frisian", "fry", "fy", NULL},
   {"Friulian", "fur", NULL, NULL},
   {"Fulah", "ful", "ff", NULL},
   {"Ga", "gaa", NULL, NULL},
   {"Gaelic; Scottish Gaelic", "gla", "gd", "gdh"},
   {"Gallegan", "glg", "gl", NULL},
   {"Ganda", "lug", "lg", NULL},
   {"Gayo", "gay", NULL, NULL},
   {"Gbaya", "gba", NULL, NULL},
   {"Geez", "gez", NULL, NULL},
   {"Georgian", "geo", "ka", "kat"},
   {"German", "ger", "de", "deu"},
   {"German, Low; Saxon, Low; Low German; Low Saxon", "nds", NULL, NULL},
   {"German, Middle High (ca.1050-1500)", "gmh", NULL, NULL},
   {"German, Old High (ca.750-1050)", "goh", NULL, NULL},
   {"Germanic (Other)", "gem", NULL, NULL},
   {"Gikuyu; Kikuyu", "kik", "ki", NULL},
   {"Gilbertese", "gil", NULL, NULL},
   {"Gondi", "gon", NULL, NULL},
   {"Gorontalo", "gor", NULL, NULL},
   {"Gothic", "got", NULL, NULL},
   {"Grebo", "grb", NULL, NULL},
   {"Greek, Ancient (to 1453)", "grc", NULL, NULL},
   {"Greek", "gre", "el", "ell"},
   {"Greenlandic; Kalaallisut", "kal", "kl", NULL},
   {"Guarani", "grn", "gn", NULL},
   {"Gujarati", "guj", "gu", NULL},
   {"GwichŽin", "gwi", NULL, NULL},
   {"Haida", "hai", NULL, NULL},
   {"Hausa", "hau", "ha", NULL},
   {"Hawaiian", "haw", NULL, NULL},
   {"Hebrew", "heb", "he", NULL},
   {"Hebrew", "heb", "iw", NULL},
   {"Herero", "her", "hz", NULL},
   {"Hiligaynon", "hil", NULL, NULL},
   {"Himachali", "him", NULL, NULL},
   {"Hindi", "hin", "hi", NULL},
   {"Hiri Motu", "hmo", "ho", NULL},
   {"Hittite", "hit", NULL, NULL},
   {"Hmong", "hmn", NULL, NULL},
   {"Hungarian", "hun", "hu", NULL},
   {"Hupa", "hup", NULL, NULL},
   {"Iban", "iba", NULL, NULL},
   {"Icelandic", "ice", "is", "isl"},
   {"Ido", "ido", "io", NULL},
   {"Igbo", "ibo", "ig", NULL},
   {"Ijo", "ijo", NULL, NULL},
   {"Iloko", "ilo", NULL, NULL},
   {"Inari Sami", "smn", NULL, NULL},
   {"Indic (Other)", "inc", NULL, NULL},
   {"Indo-European (Other)", "ine", NULL, NULL},
   {"Indonesian", "ind", "id", NULL},
   {"Ingush", "inh", NULL, NULL},
   {"Interlingua (International", "ina", "ia", NULL},
   //   {"Auxiliary Language Association)", NULL, NULL, NULL},
   {"Interlingue", "ile", "ie", NULL},
   {"Inuktitut", "iku", "iu", NULL},
   {"Inupiaq", "ipk", "ik", NULL},
   {"Iranian (Other)", "ira", NULL, NULL},
   {"Irish", "gle", "ga", "iri"},
   {"Irish, Middle (900-1200)", "mga", NULL, NULL},
   {"Irish, Old (to 900)", "sga", NULL, NULL},
   {"Iroquoian languages", "iro", NULL, NULL},
   {"Italian", "ita", "it", NULL},
   {"Japanese", "jpn", "ja", NULL},
   {"Javanese", "jav", "jv", },
   {"Judeo-Arabic", "jrb", NULL, NULL},
   {"Judeo-Persian", "jpr", NULL, NULL},
   {"Kabardian", "kbd", NULL, NULL},
   {"Kabyle", "kab", NULL, NULL},
   {"Kachin", "kac", NULL, NULL},
   {"Kalaallisut; Greenlandic", "kal", "kl", NULL},
   {"Kamba", "kam", NULL, NULL},
   {"Kannada", "kan", "kn", NULL},
   {"Kanuri", "kau", "kr", NULL},
   {"Kara-Kalpak", "kaa", NULL, NULL},
   {"Karen", "kar", NULL, NULL},
   {"Kashmiri", "kas", "ks", NULL},
   {"Kawi", "kaw", NULL, NULL},
   {"Kazakh", "kaz", "kk", NULL},
   {"Khasi", "kha", NULL, NULL},
   {"Khmer", "khm", "km", NULL},
   {"Khoisan (Other)", "khi", NULL, NULL},
   {"Khotanese", "kho", NULL, NULL},
   {"Kikuyu; Gikuyu", "kik", "ki", NULL},
   {"Kimbundu", "kmb", NULL, NULL},
   {"Kinyarwanda", "kin", "rw", NULL},
   {"Kirghiz", "kir", "ky", NULL},
   {"Klingon; tlhlngan-Hol", "tlh", NULL, NULL},
   {"Komi", "kom", "kv", NULL},
   {"Kongo", "kon", "kg", NULL},
   {"Konkani", "kok", NULL, NULL},
   {"Korean", "kor", "ko", NULL},
   {"Kosraean", "kos", NULL, NULL},
   {"Kpelle", "kpe", NULL, NULL},
   {"Kru", "kro", NULL, NULL},
   {"Kuanyama; Kwanyama", "kua", "kj", NULL},
   {"Kumyk", "kum", NULL, NULL},
   {"Kurdish", "kur", "ku", NULL},
   {"Kurukh", "kru", NULL, NULL},
   {"Kutenai", "kut", NULL, NULL},
   {"Kwanyama, Kuanyama", "kua", "kj", NULL},
   {"Ladino", "lad", NULL, NULL},
   {"Lahnda", "lah", NULL, NULL},
   {"Lamba", "lam", NULL, NULL},
   {"Lao", "lao", "lo", NULL},
   {"Latin", "lat", "la", NULL},
   {"Latvian", "lav", "lv", NULL},
   {"Letzeburgesch; Luxembourgish", "ltz", "lb", NULL},
   {"Lezghian", "lez", NULL, NULL},
   {"Limburgan; Limburger; Limburgish", "lim", "li", NULL},
   {"Limburger; Limburgan; Limburgish;", "lim", "li", NULL},
   {"Limburgish; Limburger; Limburgan", "lim", "li", NULL},
   {"Lingala", "lin", "ln", NULL},
   {"Lithuanian", "lit", "lt", NULL},
   {"Low German; Low Saxon; German, Low; Saxon, Low", "nds", NULL, NULL},
   {"Low Saxon; Low German; Saxon, Low; German, Low", "nds", NULL, NULL},
   {"Lozi", "loz", NULL, NULL},
   {"Luba-Katanga", "lub", "lu", NULL},
   {"Luba-Lulua", "lua", NULL, NULL},
   {"Luiseno", "lui", NULL, NULL},
   {"Lule Sami", "smj", NULL, NULL},
   {"Lunda", "lun", NULL, NULL},
   {"Luo (Kenya and Tanzania)", "luo", NULL, NULL},
   {"Lushai", "lus", NULL, NULL},
   {"Luxembourgish; Letzeburgesch", "ltz", "lb", NULL},
   {"Macedonian", "mac", "mk", "mkd"},
   {"Madurese", "mad", NULL, NULL},
   {"Magahi", "mag", NULL, NULL},
   {"Maithili", "mai", NULL, NULL},
   {"Makasar", "mak", NULL, NULL},
   {"Malagasy", "mlg", "mg", NULL},
   {"Malay", "may", "ms", "msa"},
   {"Malayalam", "mal", "ml", NULL},
   {"Maltese", "mlt", "mt", NULL},
   {"Manchu", "mnc", NULL, NULL},
   {"Mandar", "mdr", NULL, NULL},
   {"Mandingo", "man", NULL, NULL},
   {"Manipuri", "mni", NULL, NULL},
   {"Manobo languages", "mno", NULL, NULL},
   {"Manx", "glv", "gv", NULL},
   {"Maori", "mao", "mi", "mri"},
   {"Marathi", "mar", "mr", NULL},
   {"Mari", "chm", NULL, NULL},
   {"Marshallese", "mah", "mh", NULL},
   {"Marwari", "mwr", NULL, NULL},
   {"Masai", "mas", NULL, NULL},
   {"Mayan languages", "myn", NULL, NULL},
   {"Mende", "men", NULL, NULL},
   {"Micmac", "mic", NULL, NULL},
   {"Minangkabau", "min", NULL, NULL},
   {"Miscellaneous languages", "mis", NULL, NULL},
   {"Mohawk", "moh", NULL, NULL},
   {"Moldavian", "mol", "mo", NULL},
   {"Mon-Khmer (Other)", "mkh", NULL, NULL},
   {"Mongo", "lol", NULL, NULL},
   {"Mongolian", "mon", "mn", NULL},
   {"Mossi", "mos", NULL, NULL},
   {"Multiple languages", "mul", NULL, NULL},
   {"Munda languages", "mun", NULL, NULL},
   {"Nahuatl", "nah", NULL, NULL},
   {"Nauru", "nau", "na", NULL},
   {"Navaho, Navajo", "nav", "nv", NULL},
   {"Navajo; Navaho", "nav", "nv", NULL},
   {"Ndebele, North", "nde", "nd", NULL},
   {"Ndebele, South", "nbl", "nr", NULL},
   {"Ndonga", "ndo", "ng", NULL},
   {"Neapolitan", "nap", NULL, NULL},
   {"Nepali", "nep", "ne", NULL},
   {"Newari", "new", NULL, NULL},
   {"Nias", "nia", NULL, NULL},
   {"Niger-Kordofanian (Other)", "nic", NULL, NULL},
   {"Nilo-Saharan (Other)", "ssa", NULL, NULL},
   {"Niuean", "niu", NULL, NULL},
   {"Norse, Old", "non", NULL, NULL},
   {"North American Indian (Other)", "nai", NULL, NULL},
   {"Northern Sami", "sme", "se", NULL},
   {"North Ndebele", "nde", "nd", NULL},
   {"Norwegian", "nor", "no", NULL},
   {"Norwegian Bokmål; Bokmål, Norwegian", "nob", "nb", NULL},
   {"Norwegian Nynorsk; Nynorsk, Norwegian", "nno", "nn", NULL},
   {"Nubian languages", "nub", NULL, NULL},
   {"Nyamwezi", "nym", NULL, NULL},
   {"Nyanja; Chichewa; Chewa", "nya", "ny", NULL},
   {"Nyankole", "nyn", NULL, NULL},
   {"Nynorsk, Norwegian; Norwegian Nynorsk", "nno", "nn", NULL},
   {"Nyoro", "nyo", NULL, NULL},
   {"Nzima", "nzi", NULL, NULL},
   {"Occitan (post 1500, NULL},; Provençal", "oci", "oc", NULL},
   {"Ojibwa", "oji", "oj", NULL},
   {"Old Bulgarian; Old Slavonic; Church Slavonic;", "chu", "cu", NULL},
   {"Oriya", "ori", "or", NULL},
   {"Oromo", "orm", "om", NULL},
   {"Osage", "osa", NULL, NULL},
   {"Ossetian; Ossetic", "oss", "os", NULL},
   {"Ossetic; Ossetian", "oss", "os", NULL},
   {"Otomian languages", "oto", NULL, NULL},
   {"Pahlavi", "pal", NULL, NULL},
   {"Palauan", "pau", NULL, NULL},
   {"Pali", "pli", "pi", NULL},
   {"Pampanga", "pam", NULL, NULL},
   {"Pangasinan", "pag", NULL, NULL},
   {"Panjabi", "pan", "pa", NULL},
   {"Papiamento", "pap", NULL, NULL},
   {"Papuan (Other)", "paa", NULL, NULL},
   {"Persian", "per", "fa", "fas"},
   {"Persian, Old (ca.600-400 B.C.)", "peo", NULL, NULL},
   {"Philippine (Other)", "phi", NULL, NULL},
   {"Phoenician", "phn", NULL, NULL},
   {"Pohnpeian", "pon", NULL, NULL},
   {"Polish", "pol", "pl", NULL},
   {"Portuguese", "por", "pt", NULL},
   {"Prakrit languages", "pra", NULL, NULL},
   {"Provençal; Occitan (post 1500)", "oci", "oc", NULL},
   {"Provençal, Old (to 1500)", "pro", NULL, NULL},
   {"Pushto", "pus", "ps", NULL},
   {"Quechua", "que", "qu", NULL},
   {"Raeto-Romance", "roh", "rm", NULL},
   {"Rajasthani", "raj", NULL, NULL},
   {"Rapanui", "rap", NULL, NULL},
   {"Rarotongan", "rar", NULL, NULL},
   {"Reserved for local use", "qaa-qtz", NULL, NULL},
   {"Romance (Other)", "roa", NULL, NULL},
   {"Romanian", "rum", "ro", "ron"},
   {"Romany", "rom", NULL, NULL},
   {"Rundi", "run", "rn", NULL},
   {"Russian", "rus", "ru", NULL},
   {"Salishan languages", "sal", NULL, NULL},
   {"Samaritan Aramaic", "sam", NULL, NULL},
   {"Sami languages (Other)", "smi", NULL, NULL},
   {"Samoan", "smo", "sm", NULL},
   {"Sandawe", "sad", NULL, NULL},
   {"Sango", "sag", "sg", NULL},
   {"Sanskrit", "san", "sa", NULL},
   {"Santali", "sat", NULL, NULL},
   {"Sardinian", "srd", "sc", NULL},
   {"Sasak", "sas", NULL, NULL},
   {"Saxon, Low; German, Low; Low Saxon; Low German", "nds", NULL, NULL},
   {"Scots", "sco", NULL, NULL},
   {"Scottish Gaelic; Gaelic", "gla", "gd", NULL},
   {"Selkup", "sel", NULL, NULL},
   {"Semitic (Other)", "sem", NULL, NULL},
   {"Serbian", "scc", "sr", "srp"},
   {"Serer", "srr", NULL, NULL},
   {"Shan", "shn", NULL, NULL},
   {"Shona", "sna", "sn", NULL},
   {"Sichuan Yi", "iii", "ii", NULL},
   {"Sidamo", "sid", NULL, NULL},
   {"Sign languages", "sgn", NULL, NULL},
   {"Siksika", "bla", NULL, NULL},
   {"Sindhi", "snd", "sd", NULL},
   {"Sinhalese", "sin", "si", NULL},
   {"Sino-Tibetan (Other)", "sit", NULL, NULL},
   {"Siouan languages", "sio", NULL, NULL},
   {"Skolt Sami", "sms", NULL, NULL},
   {"Slave (Athapascan)", "den", NULL, NULL},
   {"Slavic (Other)", "sla", NULL, NULL},
   {"Slovak", "slo", "sk", "slk"},
   {"Slovenian", "slv", "sl", NULL},
   {"Sogdian", "sog", NULL, NULL},
   {"Somali", "som", "so", NULL},
   {"Songhai", "son", NULL, NULL},
   {"Soninke", "snk", NULL, NULL},
   {"Sorbian languages", "wen", NULL, NULL},
   {"Sotho, Northern", "nso", NULL, NULL},
   {"Sotho, Southern", "sot", "st", NULL},
   {"South American Indian (Other)", "sai", NULL, NULL},
   {"Southern Sami", "sma", NULL, NULL},
   {"South Ndebele", "nbl", "nr", NULL},
   {"Spanish", "spa", "es", NULL},
   {"Sukuma", "suk", NULL, NULL},
   {"Sumerian", "sux", NULL, NULL},
   {"Sundanese", "sun", "su", NULL},
   {"Susu", "sus", NULL, NULL},
   {"Swahili", "swa", "sw", NULL},
   {"Swati", "ssw", "ss", NULL},
   {"Swedish", "swe", "sv", NULL},
   {"Syriac", "syr", NULL, NULL},
   {"Tagalog", "tgl", "tl", NULL},
   {"Tahitian", "tah", "ty", NULL},
   {"Tai (Other)", "tai", NULL, NULL},
   {"Tajik", "tgk", "tg", NULL},
   {"Tamashek", "tmh", NULL, NULL},
   {"Tamil", "tam", "ta", NULL},
   {"Tatar", "tat", "tt", NULL},
   {"Telugu", "tel", "te", NULL},
   {"Tereno", "ter", NULL, NULL},
   {"Tetum", "tet", NULL, NULL},
   {"Thai", "tha", "th", NULL},
   {"Tibetan", "tib", "bo", "bod"},
   {"Tigre", "tig", NULL, NULL},
   {"Tigrinya", "tir", "ti", NULL},
   {"Timne", "tem", NULL, NULL},
   {"Tiv", "tiv", NULL, NULL},
   {"Tlingit", "tli", NULL, NULL},
   {"Tok Pisin", "tpi", NULL, NULL},
   {"Tokelau", "tkl", NULL, NULL},
   {"Tonga (Nyasa)", "tog", NULL, NULL},
   {"Tonga (Tonga Islands)", "ton", "to", NULL},
   {"Tsimshian", "tsi", NULL, NULL},
   {"Tsonga", "tso", "ts", NULL},
   {"Tswana", "tsn", "tn", NULL},
   {"Tumbuka", "tum", NULL, NULL},
   {"Tupi languages", "tup", NULL, NULL},
   {"Turkish", "tur", "tr", NULL},
   {"Turkish, Ottoman (1500-1928)", "ota", NULL, NULL},
   {"Turkmen", "tuk", "tk", NULL},
   {"Tuvalu", "tvl", NULL, NULL},
   {"Tuvinian", "tyv", NULL, NULL},
   {"Twi", "twi", "tw", NULL},
   {"Ugaritic", "uga", NULL, NULL},
   {"Uighur", "uig", "ug", NULL},
   {"Ukrainian", "ukr", "uk", NULL},
   {"Umbundu", "umb", NULL, NULL},
   {"Undetermined", "und", NULL, NULL},
   {"Urdu", "urd", "ur", NULL},
   {"Uzbek", "uzb", "uz", NULL},
   {"Vai", "vai", NULL, NULL},
   {"Venda", "ven", "ve", NULL},
   {"Vietnamese", "vie", "vi", NULL},
   {"Volapük", "vol", "vo", NULL},
   {"Votic", "vot", NULL, NULL},
   {"Wakashan languages", "wak", NULL, NULL},
   {"Walamo", "wal", NULL, NULL},
   {"Walloon", "wln", "wa", NULL},
   {"Waray", "war", NULL, NULL},
   {"Washo", "was", NULL, NULL},
   {"Welsh", "wel", "cy", "cym"},
   {"Wolof", "wol", "wo", NULL},
   {"Xhosa", "xho", "xh", NULL},
   {"Yakut", "sah", NULL, NULL},
   {"Yao", "yao", NULL, NULL},
   {"Yapese", "yap", NULL, NULL},
   {"Yiddish", "yid", "yi", NULL},
   {"Yoruba", "yor", "yo", NULL},
   {"Yupik languages", "ypk", NULL, NULL},
   {"Zande", "znd", NULL, NULL},
   {"Zapotec", "zap", NULL, NULL},
   {"Zenaga", "zen", NULL, NULL},
   {"Zhuang; Chuang", "zha", "za", NULL},
   {"Zulu", "zul", "zu", NULL},
   {"Zuni", "zun", NULL, NULL},
   {NULL, NULL, NULL}};

bool
is_valid_iso639_2_code(const char *iso639_2_code) {
  int i;

  i = 0;
  while (iso639_languages[i].iso639_2_code != NULL) {
    if (!strcmp(iso639_languages[i].iso639_2_code, iso639_2_code))
      return true;
    i++;
  }

  return false;
}

void
list_iso639_languages() {
  int i;

  i = 0;
  mxinfo(Y("                             English language name | ISO639-2 code | ISO639-1 code\n"
           "---------------------------------------------------+---------------+--------------\n"));
  while (iso639_languages[i].iso639_2_code != NULL) {
    mxinfo(boost::format("%|1$50s| | %|2$13s| | %|3$13s|\n")
           % (NULL != iso639_languages[i].english_name  ? iso639_languages[i].english_name  : "")
           % iso639_languages[i].iso639_2_code
           % (NULL != iso639_languages[i].iso639_1_code ? iso639_languages[i].iso639_1_code : ""));
    i++;
  }
}

const char *
map_iso639_2_to_iso639_1(const char *iso639_2_code) {
  uint32_t i;

  for (i = 0; iso639_languages[i].iso639_2_code != NULL; i++)
    if (!strcmp(iso639_2_code, iso639_languages[i].iso639_2_code))
      return iso639_languages[i].iso639_1_code;

  return NULL;
}

bool
is_popular_language(const char *lang) {
  return
    !strcmp(lang, "Chinese") ||
    !strcmp(lang, "Dutch") ||
    !strcmp(lang, "English") ||
    !strcmp(lang, "Finnish") ||
    !strcmp(lang, "French") ||
    !strcmp(lang, "German") ||
    !strcmp(lang, "Italian") ||
    !strcmp(lang, "Japanese") ||
    !strcmp(lang, "Norwegian") ||
    !strcmp(lang, "Portuguese") ||
    !strcmp(lang, "Russian") ||
    !strcmp(lang, "Spanish") ||
    !strcmp(lang, "Swedish");
}

bool
is_popular_language_code(const char *code) {
  return
    !strcmp(code, "chi") || // Chinese
    !strcmp(code, "dut") || // Dutch
    !strcmp(code, "eng") || // English
    !strcmp(code, "fin") || // Finnish
    !strcmp(code, "fre") || // French
    !strcmp(code, "ger") || // German
    !strcmp(code, "ita") || // Italian
    !strcmp(code, "jpn") || // Japanese
    !strcmp(code, "nor") || // Norwegian
    !strcmp(code, "por") || // Portuguese
    !strcmp(code, "rus") || // Russian
    !strcmp(code, "spa") || // Spanish
    !strcmp(code, "swe");   // Swedish
}

/** \brief Map a string to a ISO 639-2 language code

   Searches the array of ISO 639 codes. If \c s is a valid ISO 639-2
   code, a valid ISO 639-1 code, a valid terminology abbreviation
   for an ISO 639-2 code or the English name for an ISO 639-2 code
   then it returns the index of that entry in the \c iso639_languages array.

   \param c The string to look for in the array of ISO 639 codes.
   \return The index into the \c iso639_languages array if found or
     \c -1 if no such entry was found.
*/
int
map_to_iso639_2_code(const char *s,
                     bool allow_short_english_name) {
  int i, j, len;
  vector<string> names;

  for (i = 0; NULL != iso639_languages[i].iso639_2_code; ++i)
    if (!strcmp(iso639_languages[i].iso639_2_code, s) ||
        ((NULL != iso639_languages[i].terminology_abbrev) &&
         !strcmp(iso639_languages[i].terminology_abbrev, s)) ||
        ((NULL != iso639_languages[i].iso639_1_code) &&
         !strcmp(iso639_languages[i].iso639_1_code, s)))
      return i;

  for (i = 0; NULL != iso639_languages[i].iso639_2_code; ++i) {
    names = split(iso639_languages[i].english_name, ";");
    strip(names);
    for (j = 0; names.size() > j; ++j)
      if (!strcasecmp(s, names[j].c_str()))
        return i;
  }

  if (!allow_short_english_name)
    return -1;

  len = strlen(s);
  for (i = 0; NULL != iso639_languages[i].iso639_2_code; ++i) {
    names = split(iso639_languages[i].english_name, ";");
    strip(names);
    for (j = 0; names.size() > j; ++j)
      if (!strncasecmp(s, names[j].c_str(), len))
        return i;
  }


  return -1;
}

