/**
 * The copyrights, all other intellectual and industrial 
 * property rights are retained by XMOS and/or its licensors. 
 * Terms and conditions covering the use of this code can
 * be found in the Xmos End User License Agreement.
 *
 * Copyright XMOS Ltd 2011
 *
 * In the case where this code is a modification of existing code
 * under a separate license, the separate license terms are shown
 * below. The modifications to the code are still covered by the 
 * copyright notice above.
 *
 **/

short arctg_table[1024+6]={//
        0,	1,	1,	2,	3,	3,	4,	4,	5,	6,	6,	7,	8,	8,	9,	10,	10,	11,	11,	12,	13,	13,	14,	15,	15,	16,	17,
        17,	18,	18,	19,	20,	20,	21,	22,	22,	23,	24,	24,	25,	25,	26,	27,	27,	28,	29,	29,	30,	31,	31,	32,	32,	33,	34,
        34,	35,	36,	36,	37,	38,	38,	39,	39,	40,	41,	41,	42,	43,	43,	44,	45,	45,	46,	46,	47,	48,	48,	49,	50,	50,	51,
       	52,	52,	53,	53,	54,	55,	55,	56,	57,	57,	58,	58,	59,	60,	60,	61,	62,	62,	63,	64,	64,	65,	65,	66,	67,	67,	68,
       	69,	69,	70,	70,	71,	72,	72,	73,	74,	74,	75,	75,	76,	77,	77,	78,	79,	79,	80,	81,	81,	82,	82,	83,	84,	84,	85,
       	86,	86,	87,	87,	88,	89,	89,	90,	91,	91,	92,	92,	93,	94,	94,	95,	96,	96,	97,	97,	98,	99,	99,	100,	101,	101,
       	102,	102,	103,	104,	104,	105,	105,	106,	107,	107,	108,	109,	109,	110,	110,	111,	112,	112,
       	113,	114,	114,	115,	115,	116,	117,	117,	118,	118,	119,	120,	120,	121,	122,	122,	123,	123,
       	124,	125,	125,	126,	126,	127,	128,	128,	129,	130,	130,	131,	131,	132,	133,	133,	134,	134,
       	135,	136,	136,	137,	137,	138,	139,	139,	140,	141,	141,	142,	142,	143,	144,	144,	145,	145,
       	146,	147,	147,	148,	148,	149,	150,	150,	151,	151,	152,	153,	153,	154,	154,	155,	156,	156,
       	157,	157,	158,	159,	159,	160,	160,	161,	162,	162,	163,	163,	164,	165,	165,	166,	166,	167,
       	168,	168,	169,	169,	170,	171,	171,	172,	172,	173,	174,	174,	175,	175,	176,	177,	177,	178,
       	178,	179,	179,	180,	181,	181,	182,	182,	183,	184,	184,	185,	185,	186,	187,	187,	188,	188,
       	189,	189,	190,	191,	191,	192,	192,	193,	194,	194,	195,	195,	196,	196,	197,	198,	198,	199,
       	199,	200,	201,	201,	202,	202,	203,	203,	204,	205,	205,	206,	206,	207,	207,	208,	209,	209,
       	210,	210,	211,	211,	212,	213,	213,	214,	214,	215,	215,	216,	217,	217,	218,	218,	219,	219,
      	220,	221,	221,	222,	222,	223,	223,	224,	225,	225,	226,	226,	227,	227,	228,	228,	229,	230,
      	230,	231,	231,	232,	232,	233,	234,	234,	235,	235,	236,	236,	237,	237,	238,	239,	239,	240,
      	240,	241,	241,	242,	242,	243,	244,	244,	245,	245,	246,	246,	247,	247,	248,	248,	249,	250,
      	250,	251,	251,	252,	252,	253,	253,	254,	255,	255,	256,	256,	257,	257,	258,	258,	259,	259,
      	260,	260,	261,	262,	262,	263,	263,	264,	264,	265,	265,	266,	266,	267,	267,	268,	269,	269,
      	270,	270,	271,	271,	272,	272,	273,	273,	274,	274,	275,	275,	276,	277,	277,	278,	278,	279,
      	279,	280,	280,	281,	281,	282,	282,	283,	283,	284,	284,	285,	285,	286,	287,	287,	288,	288,
      	289,	289,	290,	290,	291,	291,	292,	292,	293,	293,	294,	294,	295,	295,	296,	296,	297,	297,
      	298,	298,	299,	299,	300,	300,	301,	301,	302,	303,	303,	304,	304,	305,	305,	306,	306,	307,
      	307,	308,	308,	309,	309,	310,	310,	311,	311,	312,	312,	313,	313,	314,	314,	315,	315,	316,
      	316,	317,	317,	318,	318,	319,	319,	320,	320,	321,	321,	322,	322,	323,	323,	324,	324,	325,
      	325,	326,	326,	327,	327,	327,	328,	328,	329,	329,	330,	330,	331,	331,	332,	332,	333,	333,
      	334,	334,	335,	335,	336,	336,	337,	337,	338,	338,	339,	339,	340,	340,	341,	341,	342,	342,
      	342,	343,	343,	344,	344,	345,	345,	346,	346,	347,	347,	348,	348,	349,	349,	350,	350,	351,
      	351,	351,	352,	352,	353,	353,	354,	354,	355,	355,	356,	356,	357,	357,	358,	358,	358,	359,
      	359,	360,	360,	361,	361,	362,	362,	363,	363,	364,	364,	364,	365,	365,	366,	366,	367,	367,
      	368,	368,	369,	369,	369,	370,	370,	371,	371,	372,	372,	373,	373,	374,	374,	374,	375,	375,
      	376,	376,	377,	377,	378,	378,	378,	379,	379,	380,	380,	381,	381,	382,	382,	382,	383,	383,
      	384,	384,	385,	385,	386,	386,	386,	387,	387,	388,	388,	389,	389,	389,	390,	390,	391,	391,
      	392,	392,	392,	393,	393,	394,	394,	395,	395,	396,	396,	396,	397,	397,	398,	398,	399,	399,
      	399,	400,	400,	401,	401,	401,	402,	402,	403,	403,	404,	404,	404,	405,	405,	406,	406,	407,
      	407,	407,	408,	408,	409,	409,	409,	410,	410,	411,	411,	412,	412,	412,	413,	413,	414,	414,
      	414,	415,	415,	416,	416,	417,	417,	417,	418,	418,	419,	419,	419,	420,	420,	421,	421,	421,
      	422,	422,	423,	423,	423,	424,	424,	425,	425,	425,	426,	426,	427,	427,	427,	428,	428,	429,
      	429,	429,	430,	430,	431,	431,	431,	432,	432,	433,	433,	433,	434,	434,	435,	435,	435,	436,
      	436,	437,	437,	437,	438,	438,	439,	439,	439,	440,	440,	440,	441,	441,	442,	442,	442,	443,
      	443,	444,	444,	444,	445,	445,	445,	446,	446,	447,	447,	447,	448,	448,	449,	449,	449,	450,
      	450,	450,	451,	451,	452,	452,	452,	453,	453,	453,	454,	454,	455,	455,	455,	456,	456,	456,
      	457,	457,	458,	458,	458,	459,	459,	459,	460,	460,	461,	461,	461,	462,	462,	462,	463,	463,
      	463,	464,	464,	465,	465,	465,	466,	466,	466,	467,	467,	467,	468,	468,	469,	469,	469,	470,
      	470,	470,	471,	471,	471,	472,	472,	473,	473,	473,	474,	474,	474,	475,	475,	475,	476,	476,
      	476,	477,	477,	477,	478,	478,	479,	479,	479,	480,	480,	480,	481,	481,	481,	482,	482,	482,
      	483,	483,	483,	484,	484,	484,	485,	485,	485,	486,	486,	487,	487,	487,	488,	488,	488,	489,
      	489,	489,	490,	490,	490,	491,	491,	491,	492,	492,	492,	493,	493,	493,	494,	494,	494,	495,
      	495,	495,	496,	496,	496,	497,	497,	497,	498,	498,	498,	499,	499,	499,	500,	500,	500,	501,
      	501,	501,	502,	502,	502,	503,	503,	503,	504,	504,	504,	505,	505,	505,	506,	506,	506,	507,
      	507,	507,	508,	508,	508,	508,	509,	509,	509,	510,	510,	510,	511,	511,	511,	512,	512,    512};



short sine_third[256]={
		0,345,690,1032,1371,1706,2036,2360,//
		2677,2986,3287,3577,3858,4127,4385,4630,//
		4862,5081,5286,5477,5654,5816,5963,6095,//
		6213,6315,6403,6477,6536,6581,6613,6631,//
		6637,6631,6614,6586,6548,6501,6445,6382,//
		6311,6235,6154,6068,5979,5887,5794,5700,//
		5606,5513,5422,5333,5248,5167,5090,5019,//
		4954,4895,4842,4798,4760,4731,4710,4698,//
		4693,4698,4710,4731,4760,4798,4842,4895,//
		4954,5019,5090,5167,5248,5333,5422,5513,//
		5606,5700,5794,5887,5979,6068,6154,6235,//
		6311,6382,6445,6501,6548,6586,6614,6631,//
		6637,6631,6613,6581,6536,6477,6403,6315,//
		6213,6095,5963,5816,5654,5477,5286,5081,//
		4862,4630,4385,4127,3858,3577,3287,2986,//
		2677,2360,2036,1706,1371,1032,690,345,//
		//
		0,-345,-690,-1032,-1371,-1706,-2036,-2360,//
		-2677,-2986,-3287,-3577,-3858,-4127,-4385,-4630,//
		-4862,-5081,-5286,-5477,-5654,-5816,-5963,-6095,//
		-6213,-6315,-6403,-6477,-6536,-6581,-6613,-6631,//
		-6637,-6631,-6614,-6586,-6548,-6501,-6445,-6382,//
		-6311,-6235,-6154,-6068,-5979,-5887,-5794,-5700,//
		-5606,-5513,-5422,-5333,-5248,-5167,-5090,-5019,//
		-4954,-4895,-4842,-4798,-4760,-4731,-4710,-4698,//
		-4693,-4698,-4710,-4731,-4760,-4798,-4842,-4895,//
		-4954,-5019,-5090,-5167,-5248,-5333,-5422,-5513,//
		-5606,-5700,-5794,-5887,-5979,-6068,-6154,-6235,//
		-6311,-6382,-6445,-6501,-6548,-6586,-6614,-6631,//
		-6637,-6631,-6613,-6581,-6536,-6477,-6403,-6315,//
		-6213,-6095,-5963,-5816,-5654,-5477,-5286,-5081,//
		-4862,-4630,-4385,-4127,-3858,-3577,-3287,-2986,//
		-2677,-2360,-2036,-1706,-1371,-1032,-690,-345,//
};

short sine_table[256] = {
	0	,
	403		,
	805		,
	1207	,
	1609	,
	2009	,
	2408	,
	2806	,
	3202	,
	3596	,
	3988	,
	4378	,
	4765	,
	5148	,
	5529	,
	5907	,
	6281	,
	6651	,
	7017	,
	7379	,
	7736	,
	8089	,
	8437	,
	8780	,
	9117	,
	9449	,
	9775	,
	10096	,
	10410	,
	10718	,
	11019	,
	11314	,
	11602	,
	11883	,
	12156	,
	12423	,
	12682	,
	12933	,
	13176	,
	13412	,
	13639	,
	13858	,
	14069	,
	14271	,
	14464	,
	14649	,
	14825	,
	14992	,
	15150	,
	15299	,
	15438	,
	15568	,
	15689	,
	15800	,
	15902	,
	15994	,
	16077	,
	16149	,
	16212	,
	16265	,
	16309	,
	16342	,
	16366	,
	16379	,
	16383	,
	16377	,
	16361	,
	16335	,
	16299	,
	16253	,
	16198	,
	16132	,
	16057	,
	15973	,
	15878	,
	15774	,
	15661	,
	15538	,
	15405	,
	15263	,
	15112	,
	14952	,
	14783	,
	14605	,
	14418	,
	14222	,
	14018	,
	13806	,
	13584	,
	13355	,
	13118	,
	12873	,
	12619	,
	12359	,
	12091	,
	11815	,
	11532	,
	11243	,
	10946	,
	10643	,
	10334	,
	10018	,
	9697	,
	9369	,
	9036	,
	8697	,
	8353	,
	8004	,
	7650	,
	7291	,
	6928	,
	6561	,
	6190	,
	5815	,
	5437	,
	5055	,
	4671	,
	4283	,
	3893	,
	3501	,
	3106	,
	2710	,
	2312	,
	1912	,
	1511	,
	1110	,
	708	,
	305	,
	-98	,
	-501	,
	-903	,
	-1305	,
	-1706	,
	-2106	,
	-2505	,
	-2903	,
	-3298	,
	-3692	,
	-4083	,
	-4472	,
	-4858	,
	-5241	,
	-5621	,
	-5998	,
	-6371	,
	-6740	,
	-7105	,
	-7466	,
	-7823	,
	-8174	,
	-8521	,
	-8862	,
	-9198	,
	-9529	,
	-9854	,
	-10173	,
	-10485	,
	-10792	,
	-11091	,
	-11385	,
	-11671	,
	-11950	,
	-12222	,
	-12486	,
	-12743	,
	-12993	,
	-13234	,
	-13468	,
	-13693	,
	-13910	,
	-14119	,
	-14319	,
	-14510	,
	-14693	,
	-14866	,
	-15031	,
	-15187	,
	-15333	,
	-15471	,
	-15599	,
	-15717	,
	-15826	,
	-15925	,
	-16015	,
	-16095	,
	-16165	,
	-16226	,
	-16277	,
	-16318	,
	-16349	,
	-16370	,
	-16381	,
	-16382	,
	-16374	,
	-16355	,
	-16327	,
	-16289	,
	-16241	,
	-16183	,
	-16115	,
	-16038	,
	-15951	,
	-15854	,
	-15747	,
	-15632	,
	-15506	,
	-15371	,
	-15228	,
	-15074	,
	-14912	,
	-14741	,
	-14560	,
	-14371	,
	-14174	,
	-13967	,
	-13753	,
	-13529	,
	-13298	,
	-13059	,
	-12812	,
	-12557	,
	-12294	,
	-12024	,
	-11747	,
	-11463	,
	-11171	,
	-10873	,
	-10569	,
	-10258	,
	-9941	,
	-9617	,
	-9288	,
	-8954	,
	-8614	,
	-8268	,
	-7918	,
	-7563	,
	-7204	,
	-6840	,
	-6471	,
	-6099	,
	-5724	,
	-5345	,
	-4962	,
	-4577	,
	-4189	,
	-3798	,
	-3405	,
	-3010	,
	-2613	,
	-2214	,
	-1815	,
	-1414	,
	-1012	,
	-610	,
	-207
};

//** space vector table with 1024 base points
//** Umax = 6944
short SPACE_TABLE[1024]={//
0,70,139,209,278,348,418,487,//
557,626,696,766,836,905,975,1044,//
1114,1183,1252,1322,1391,1460,1531,1600,//
1669,1738,1807,1876,1945,2014,2083,2152,//
2222,2290,2359,2428,2496,2565,2633,2702,//
2770,2839,2907,2976,3044,3112,3180,3248,//
3316,3383,3451,3519,3586,3654,3722,3789,//
3856,3923,3990,4057,4124,4191,4257,4324,//
4391,4458,4524,4590,4656,4722,4788,4853,//
4919,4984,5050,5116,5181,5246,5311,5376,//
5440,5505,5569,5634,5698,5762,5772,5781,//
5791,5800,5810,5819,5828,5837,5846,5854,//
5862,5870,5878,5887,5894,5902,5910,5917,//
5925,5932,5939,5944,5951,5958,5964,5970,//
5976,5982,5988,5993,5999,6003,6008,6013,//
6017,6022,6026,6030,6034,6038,6042,6045,//
6047,6050,6053,6056,6058,6060,6063,6064,//
6066,6068,6069,6069,6070,6071,6071,6072,//
6072,6072,6071,6071,6070,6068,6067,6066,//
6064,6063,6061,6059,6056,6054,6051,6048,//
6044,6040,6037,6033,6029,6024,6020,6015,//
6010,6005,5999,5994,5988,5982,5975,5969,//
5962,5955,5948,5940,5933,5924,5915,5907,//
5898,5889,5880,5871,5861,5851,5841,5831,//
5819,5809,5798,5786,5775,5763,5751,5739,//
5726,5713,5699,5686,5673,5659,5645,5631,//
5616,5601,5586,5571,5555,5539,5523,5506,//
5490,5473,5456,5439,5421,5403,5385,5367,//
5348,5329,5310,5290,5271,5251,5231,5210,//
5190,5169,5147,5125,5104,5082,5060,5037,//
5015,4992,4968,4945,4921,4896,4872,4847,//
4823,4798,4772,4747,4721,4695,4668,4642,//
4669,4696,4722,4749,4775,4801,4826,4852,//
4877,4901,4927,4951,4975,4999,5022,5046,//
5069,5091,5114,5136,5158,5180,5202,5223,//
5244,5264,5285,5305,5325,5344,5364,5384,//
5403,5421,5439,5457,5475,5493,5510,5527,//
5544,5560,5578,5594,5609,5625,5640,5655,//
5670,5685,5699,5713,5727,5741,5754,5767,//
5780,5793,5805,5817,5829,5840,5852,5864,//
5874,5885,5895,5905,5915,5925,5934,5943,//
5952,5961,5970,5979,5987,5994,6002,6009,//
6016,6023,6029,6036,6042,6048,6053,6059,//
6064,6069,6074,6078,6083,6087,6091,6095,//
6099,6102,6105,6108,6110,6113,6115,6117,//
6118,6120,6122,6123,6124,6125,6125,6126,//
6126,6126,6125,6125,6125,6124,6123,6122,//
6120,6118,6117,6114,6112,6110,6107,6105,//
6102,6099,6096,6092,6088,6084,6080,6076,//
6071,6067,6063,6058,6053,6047,6042,6036,//
6030,6024,6018,6012,6006,5999,5993,5986,//
5979,5971,5964,5956,5948,5941,5932,5925,//
5917,5908,5900,5891,5882,5873,5864,5854,//
5845,5835,5772,5708,5644,5580,5515,5451,//
5386,5322,5257,5192,5126,5061,4996,4930,//
4865,4799,4734,4668,4602,4536,4470,4403,//
4336,4270,4203,4137,4070,4003,3936,3869,//
3802,3734,3667,3600,3532,3465,3397,3329,//
3262,3194,3126,3058,2989,2921,2853,2785,//
2716,2648,2579,2511,2442,2374,2305,2235,//
2167,2098,2029,1960,1891,1822,1753,1684,//
1615,1545,1476,1406,1337,1268,1198,1129,//
1060,990,921,851,781,711,642,572,//
503,433,364,294,224,155,85,16,//
-54,-123,-192,-262,-331,-401,-471,-540,//
-610,-680,-750,-819,-889,-958,-1028,-1097,//
-1167,-1236,-1305,-1375,-1445,-1514,-1584,-1653,//
-1722,-1791,-1860,-1929,-1998,-2067,-2137,-2206,//
-2275,-2343,-2412,-2481,-2549,-2618,-2686,-2755,//
-2823,-2893,-2961,-3029,-3097,-3165,-3233,-3301,//
-3369,-3436,-3504,-3572,-3640,-3708,-3775,-3842,//
-3909,-3976,-4043,-4110,-4177,-4244,-4311,-4378,//
-4444,-4511,-4577,-4643,-4709,-4775,-4841,-4906,//
-4972,-5038,-5104,-5169,-5234,-5299,-5364,-5429,//
-5493,-5558,-5622,//
-5634,-5698,-5762,-5772,-5781,-5791,-5800,-5810,//
-5819,-5828,-5837,-5846,-5854,-5862,-5870,-5878,//
-5887,-5894,-5902,-5910,-5917,-5925,-5932,-5939,//
-5944,-5951,-5958,-5964,-5970,-5976,-5982,-5988,//
-5993,-5999,-6003,-6008,-6013,-6017,-6022,-6026,//
-6030,-6034,-6038,-6042,-6045,-6047,-6050,-6053,//
-6056,-6058,-6060,-6063,-6064,-6066,-6068,-6069,//
-6069,-6070,-6071,-6071,-6072,-6072,-6072,-6071,//
-6071,-6070,-6068,-6067,-6066,-6064,-6063,-6061,//
-6059,-6056,-6054,-6051,-6048,-6044,-6040,-6037,//
-6033,-6029,-6024,-6020,-6015,-6010,-6005,-5999,//
-5994,-5988,-5982,-5975,-5969,-5962,-5955,-5948,//
-5940,-5933,-5924,-5915,-5907,-5898,-5889,-5880,//
-5871,-5861,-5851,-5841,-5831,-5819,-5809,-5798,//
-5786,-5775,-5763,-5751,-5739,-5726,-5713,-5699,//
-5686,-5673,-5659,-5645,-5631,-5616,-5601,-5586,//
-5571,-5555,-5539,-5523,-5506,-5490,-5473,-5456,//
-5439,-5421,-5403,-5385,-5367,-5348,-5329,-5310,//
-5290,-5271,-5251,-5231,-5210,-5190,-5169,-5147,//
-5125,-5104,-5082,-5060,-5037,-5015,-4992,-4968,//
-4945,-4921,-4896,-4872,-4847,-4823,-4798,-4772,//
-4747,-4721,-4695,-4668,-4642,-4669,-4696,-4722,//
-4749,-4775,-4801,-4826,-4852,-4877,-4901,-4927,//
-4951,-4975,-4999,-5022,-5046,-5069,-5091,-5114,//
-5136,-5158,-5180,-5202,-5223,-5244,-5264,-5285,//
-5305,-5325,-5344,-5364,-5384,-5403,-5421,-5439,//
-5457,-5475,-5493,-5510,-5527,-5544,-5560,-5578,//
-5594,-5609,-5625,-5640,-5655,-5670,-5685,-5699,//
-5713,-5727,-5741,-5754,-5767,-5780,-5793,-5805,//
-5817,-5829,-5840,-5852,-5864,-5874,-5885,-5895,//
-5905,-5915,-5925,-5934,-5943,-5952,-5961,-5970,//
-5979,-5987,-5994,-6002,-6009,-6016,-6023,-6029,//
-6036,-6042,-6048,-6053,-6059,-6064,-6069,-6074,//
-6078,-6083,-6087,-6091,-6095,-6099,-6102,-6105,//
-6108,-6110,-6113,-6115,-6117,-6118,-6120,-6122,//
-6123,-6124,-6125,-6125,-6126,-6126,-6126,-6125,//
-6125,-6125,-6124,-6123,-6122,-6120,-6118,-6117,//
-6114,-6112,-6110,-6107,-6105,-6102,-6099,-6096,//
-6092,-6088,-6084,-6080,-6076,-6071,-6067,-6063,//
-6058,-6053,-6047,-6042,-6036,-6030,-6024,-6018,//
-6012,-6006,-5999,-5993,-5986,-5979,-5971,-5964,//
-5956,-5948,-5941,-5932,-5925,-5917,-5908,-5900,//
-5891,-5882,-5873,-5864,-5854,-5845,-5835,-5772,//
-5708,-5644,-5580,-5515,-5451,-5386,-5322,-5257,//
-5192,-5126,-5061,-4996,-4930,-4865,-4799,-4734,//
-4668,-4602,-4536,-4470,-4403,-4336,-4270,-4203,//
-4137,-4070,-4003,-3936,-3869,-3802,-3734,-3667,//
-3600,-3532,-3465,-3397,-3329,-3262,-3194,-3126,//
-3058,-2989,-2921,-2853,-2785,-2716,-2648,-2579,//
-2511,-2442,-2374,-2305,-2235,-2167,-2098,-2029,//
-1960,-1891,-1822,-1753,-1684,-1615,-1545,-1476,//
-1406,-1337,-1268,-1198,-1129,-1060,-990,-921,//
-851,-781,-711,-642,-572,-503,-433,-364,//
-294,-224,-155,-85,-16,//
};
