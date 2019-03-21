#include "ecos.h"
#include "minunit.h"
idxint random_unbounded_n = 120;
idxint random_unbounded_m = 120;
idxint random_unbounded_p = 12;
idxint random_unbounded_l = 0;
idxint random_unbounded_ncones = 20;
idxint random_unbounded_nexc = 20;
pfloat random_unbounded_c[120] = {9.648869937320769807e-02, -2.419758939011430243e+00, -1.001342788659201899e+00, 2.811149990995901238e+00, 2.039857302324946886e+00, -7.356384479498672135e-01, 4.251637302868410018e+00, -5.296589456078716340e-01, 7.917320138198011836e-01, 2.838117850306578926e+00, -2.509900124935787957e+00, -3.616424812158292035e-02, 1.444354185310919192e+00, 1.267859431424379846e+00, 2.972895304331224064e+00, 5.547338719883894598e+00, 3.019069729274515446e+00, -2.407573683415450416e-01, 2.728540324322471733e+00, 8.146587856696456686e-01, -2.263681811169477420e+00, 2.571649304058075014e+00, -6.168266909321988845e-01, 4.991501082678937995e-01, 3.090247778862063477e+00, 3.334782743330007015e+00, 4.029877366504190372e-01, 8.620869193845865919e-01, -5.124085532391141617e-01, -3.686865601799766412e-01, 2.528753038221813743e+00, 6.064685209899876028e-01, 2.025127826034587297e+00, 3.033246775981156329e+00, -1.401996844621773652e+00, 1.270548156670007423e+00, 2.317776365161653640e+00, -9.849572101439584282e-01, 2.798515519130622131e+00, 1.228646316348648071e+00, 7.279302248567186551e-01, 3.620331801192105736e+00, 3.491795714770538961e+00, -3.877359049767276078e-01, -4.860960282451104453e-01, 5.231575441392105397e+00, 2.801288727944517554e-01, -9.060802600005157803e-02, 3.903492774557073552e+00, -2.163115676538329701e+00, -9.604167450711298404e-01, 6.061986517964789378e+00, -1.734260108553319579e+00, 2.471531627409738086e+00, 2.048528569298255775e+00, 1.912040925776576694e+00, -8.223318642901433773e-01, 4.227259450210276270e+00, -2.324722831155305425e+00, 7.001525721089405518e-01, 9.679296177913128130e-01, 8.778964346623592263e-01, -1.004320188588339047e+00, -2.169895754676372412e+00, -3.851292261085870194e-01, -1.800171225303623945e-01, -2.583335054610269133e+00, 1.610045136146341038e+00, 5.527715043134192596e-01, -2.548340548785388293e-01, 2.328769228215346043e-01, 1.744286174473180573e+00, -4.615220016029882855e-01, 8.931180606590616300e-01, 8.171029841126682403e-01, 7.827234103970213130e-01, 1.973143419389347564e+00, 7.123102857621976813e-01, 1.227566089055729170e+00, 1.856792173873237584e+00, 9.773184808734162177e-01, 3.768205513820495067e-01, 2.209083291424331907e-01, 2.745375056664139390e-01, -1.554230426698320455e+00, 1.001159323521845446e+00, 1.195134648995420212e+00, -8.541558017158179528e-01, 1.010915834827929904e+00, 2.167768331790470349e+00, -3.620052844129146852e-01, 4.005416486036777357e+00, 3.498437921939502537e+00, -1.572636521507628338e+00, 1.081645837990279357e-01, -7.225055898082142214e-01, -1.933681107909336117e+00, 4.399908737293678485e-03, 1.455321141283418829e+00, -5.336115817170724585e-01, 7.861845667796225623e-01, 8.815870686846277726e-01, -1.844704052679265516e+00, 1.444792608186729055e+00, -2.511566574310658551e-01, -3.582783387427277422e-01, 1.533473051063031445e+00, -4.624681459765711544e-01, -2.559820918888489061e-02, -2.124201011988311460e-01, 6.541186710077407929e-01, -4.247955560065957981e-01, 4.657236904508844866e+00, 1.869470267940233077e-01, -2.993612900144557720e+00, 1.275409591393375619e+00, 4.181869184646341830e-01, 6.976561047608353938e-02, -8.968872771145020018e-02, 1.343792457465150747e+00};
idxint random_unbounded_Gjc[121] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120};
idxint random_unbounded_Gir[120] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
pfloat random_unbounded_Gpr[120] = {1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000444e+00, 1.000000000000000222e+00, 1.000000000000000444e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000666e+00, 1.000000000000000222e+00, 1.000000000000000444e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 9.999999999999998890e-01, 1.000000000000000444e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000444e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 9.999999999999998890e-01, 1.000000000000000666e+00, 1.000000000000000222e+00, 1.000000000000000444e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000000e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 9.999999999999996669e-01, 1.000000000000000000e+00, 1.000000000000000222e+00, 9.999999999999998890e-01, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000444e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000444e+00, 1.000000000000000000e+00, 1.000000000000000444e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000222e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00, 1.000000000000000000e+00};
pfloat random_unbounded_h[120] = {1.208722743612735906e+00, -1.410097655081738344e+00, 4.282500329424399066e-01, 1.397782511240277969e+00, 3.201503888217223093e-01, 1.458310327661976435e+00, 2.462091228960971989e+00, 1.068644132641356492e+00, -2.217664402791573508e+00, 3.127220991381551851e-01, 1.266130192286748057e+00, -1.842246936782981681e+00, 8.651541078670509366e-01, -3.405243608070752659e-01, 6.441810238522933663e-01, 2.322736463516473560e+00, 2.409501886110070767e+00, 3.067995442567382769e-01, 3.324580311849608449e+00, -2.464235831210537242e+00, -1.497966998121813331e+00, 2.032257473210487664e+00, -2.342695866170190655e+00, -8.782373588379815965e-01, 1.547162880073068347e+00, 4.176466978148086207e-01, -4.463571472791598715e-01, 2.052779848077525671e+00, -1.140231956848992034e+00, -5.640336410186969074e-01, 1.879459162150805662e+00, 5.084384961838073203e-01, -1.554386980778127203e+00, 2.755825736646130064e+00, 2.418454464059117015e+00, -2.101466202493029289e+00, 3.182210521228999944e+00, 1.464116490309635310e+00, 3.927196353926246108e-01, 3.599591156294717376e+00, -6.114372094139038927e-01, -3.102997903028170246e+00, 2.614745389073803494e+00, 2.513867232556148856e+00, 8.913741078598250711e-01, 2.525934799965367183e+00, -1.164975101341503727e+00, -1.912485172751227980e+00, 4.119167540320163745e+00, 5.360031031652963129e-01, 1.808153041905389058e+00, 1.133134397394264248e+00, 1.876014526249126124e+00, 6.979083902645395465e-01, 2.721204841527642859e+00, 8.522964529450325344e-01, -8.721789663157715200e-01, 1.945081152471926256e+00, -1.532377485744410794e+00, -4.312346112681723631e-01, -1.359844592974151167e+00, 2.734830381358340112e+00, 5.157407174112071946e-01, -5.966073147806678634e-01, 9.473671424787553086e-01, 1.502832489983885189e+00, -7.134800436183833527e-01, 1.497497840620798826e+00, -7.677359605663478526e-01, -5.004476511000047756e-01, 6.672533156822053613e-01, 1.828364096409152317e+00, -9.742131306212924446e-01, 1.305270738922728935e+00, -1.036265715301148971e-01, -4.283071780095875081e-01, 4.593930820594792630e-01, 2.043030095265862212e+00, 4.261525215688213297e-01, 3.302789297300835258e+00, -4.895159077960025140e-01, -1.110090781149598582e+00, -3.435891997781448381e-02, 1.363091031242502416e+00, -1.490531917080755386e+00, 8.134484686200824655e-01, 4.883367258599254912e-01, -4.427826598964629268e-01, 6.861004468686389135e-01, -6.094802695427843364e-01, 3.449254990652859121e-01, 3.442983320216512766e+00, 1.589484213892405906e+00, -1.336464234159749909e+00, 7.428619160266024535e-01, 4.511483032462666465e-01, -2.684459458140169730e+00, 1.801743345726066536e+00, -1.119992022836276302e+00, -8.738382507074737848e-01, 2.253105512528241317e+00, 5.646940390494442630e-01, -2.798826231985519497e-01, 7.551530683887982542e-01, 1.593641642377946477e+00, -1.229639365641134185e-01, 2.854582428088012769e+00, -3.505610566563366337e-02, -1.810263556451835232e+00, 1.270428883297218148e+00, 7.206713426914210796e-01, -3.126720676059450810e+00, 2.534273581370709572e-01, 1.879179669672388364e+00, -1.132427794799895748e+00, 1.506417964712027047e+00, 9.176150735691857019e-01, -8.867102476206938366e-01, 3.488918936343855748e+00, 2.084625808080294851e-01};
idxint random_unbounded_q[20] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
idxint random_unbounded_Ajc[121] = {0, 5, 8, 14, 16, 19, 22, 25, 28, 31, 33, 36, 44, 47, 51, 58, 64, 70, 74, 77, 85, 90, 93, 96, 101, 105, 107, 111, 118, 123, 127, 132, 138, 144, 146, 152, 155, 160, 165, 169, 172, 174, 180, 187, 187, 191, 197, 198, 207, 211, 217, 223, 231, 236, 241, 247, 253, 256, 263, 268, 275, 279, 283, 289, 293, 300, 305, 312, 314, 318, 322, 329, 332, 338, 341, 345, 350, 356, 363, 368, 372, 380, 387, 394, 395, 402, 407, 411, 415, 418, 423, 429, 435, 440, 448, 451, 456, 463, 469, 474, 480, 484, 488, 493, 499, 503, 506, 511, 516, 519, 524, 529, 531, 537, 543, 549, 554, 560, 564, 569, 573};
idxint random_unbounded_Air[573] = {0, 1, 3, 4, 8, 3, 6, 11, 2, 3, 6, 7, 8, 11, 0, 4, 0, 7, 11, 1, 7, 8, 2, 5, 6, 2, 3, 6, 5, 10, 11, 2, 5, 3, 5, 11, 1, 3, 4, 5, 6, 8, 9, 10, 3, 4, 10, 0, 3, 5, 9, 0, 2, 3, 4, 5, 7, 11, 0, 1, 2, 5, 9, 11, 2, 4, 6, 7, 9, 11, 2, 4, 7, 10, 3, 5, 9, 0, 1, 2, 3, 4, 5, 7, 10, 1, 3, 6, 9, 11, 0, 1, 5, 0, 6, 10, 2, 5, 6, 7, 8, 2, 3, 6, 9, 0, 9, 2, 5, 7, 8, 0, 1, 4, 5, 9, 10, 11, 3, 4, 7, 10, 11, 1, 4, 6, 11, 0, 3, 9, 10, 11, 0, 3, 5, 6, 8, 11, 0, 1, 2, 3, 6, 9, 7, 10, 4, 6, 7, 8, 9, 11, 5, 9, 11, 3, 4, 7, 8, 11, 1, 3, 6, 7, 8, 0, 3, 7, 10, 3, 7, 11, 0, 2, 2, 5, 6, 7, 9, 10, 0, 1, 2, 5, 7, 9, 10, 0, 6, 8, 10, 0, 2, 5, 6, 7, 11, 9, 0, 2, 4, 5, 6, 7, 9, 10, 11, 0, 3, 5, 11, 1, 2, 3, 4, 7, 11, 0, 1, 3, 5, 8, 11, 0, 2, 4, 5, 6, 7, 9, 10, 1, 3, 4, 6, 11, 1, 2, 7, 9, 10, 0, 2, 3, 7, 9, 11, 0, 1, 5, 7, 9, 11, 3, 6, 8, 0, 1, 2, 4, 6, 7, 11, 3, 5, 7, 10, 11, 1, 2, 4, 5, 6, 7, 10, 0, 2, 9, 11, 4, 7, 8, 10, 0, 1, 2, 3, 5, 6, 3, 4, 9, 10, 0, 1, 2, 3, 4, 9, 11, 1, 2, 4, 8, 10, 1, 3, 5, 6, 8, 9, 10, 7, 8, 0, 2, 3, 8, 5, 8, 9, 10, 1, 3, 4, 6, 8, 9, 10, 2, 3, 9, 2, 4, 6, 9, 10, 11, 2, 3, 6, 0, 3, 5, 8, 1, 2, 5, 7, 11, 2, 4, 8, 9, 10, 11, 1, 4, 5, 6, 7, 8, 11, 4, 5, 6, 7, 9, 2, 6, 8, 10, 0, 1, 2, 3, 4, 5, 6, 9, 5, 6, 7, 8, 9, 10, 11, 0, 3, 4, 7, 8, 9, 11, 4, 1, 3, 5, 6, 7, 8, 11, 0, 1, 3, 5, 7, 2, 3, 10, 11, 2, 3, 7, 10, 1, 2, 5, 1, 4, 5, 9, 10, 3, 5, 6, 7, 10, 11, 0, 4, 5, 7, 8, 9, 0, 1, 5, 7, 9, 0, 1, 3, 4, 6, 8, 9, 10, 1, 10, 11, 0, 1, 3, 6, 7, 1, 2, 3, 6, 7, 10, 11, 0, 1, 2, 3, 6, 8, 0, 2, 3, 6, 10, 0, 1, 2, 8, 10, 11, 1, 2, 8, 10, 4, 5, 10, 11, 0, 3, 4, 6, 10, 1, 5, 6, 7, 9, 10, 0, 3, 7, 11, 7, 10, 11, 4, 7, 9, 10, 11, 1, 3, 5, 6, 8, 2, 7, 11, 1, 6, 8, 9, 11, 0, 8, 9, 10, 11, 0, 9, 2, 3, 5, 7, 9, 10, 4, 5, 6, 8, 10, 11, 0, 1, 3, 7, 8, 9, 3, 4, 6, 9, 10, 2, 3, 7, 8, 9, 11, 2, 6, 9, 11, 1, 2, 4, 6, 11, 3, 7, 9, 10};
pfloat random_unbounded_Apr[573] = {9.564574030232724233e-01, 8.390399999375703910e-01, 9.385254910041892495e-01, 7.302354632279580704e-01, 9.111485343188481245e-01, 3.040648462537880459e-01, 9.917877888890971327e-01, 2.612880725972812068e-01, 4.476762172541875473e-01, 8.458064943726182339e-01, 8.381195298186262521e-01, 4.842056991285207945e-01, 5.648171797140546513e-01, 3.772274832485612572e-01, 8.360035623513456526e-01, 5.630448261764868789e-01, 3.980235337022924869e-01, 7.832305250859421530e-01, 7.823344485478767041e-01, 7.239910434132047490e-01, 1.607211097124379706e-01, 5.714515257648149493e-01, 9.803485825109364837e-01, 8.308093249599524110e-01, 4.881677528933039412e-01, 8.458990479882916302e-01, 5.083693131154983780e-01, 9.162114015187814431e-01, 4.855476882956286655e-01, 8.829721606930734934e-01, 9.733742090240175004e-01, 3.562979682679644905e-02, 5.645238959948724045e-01, 9.823613543480926857e-01, 2.445525948866492660e-01, 6.606157142088234790e-01, 7.619333518368933689e-01, 3.317472476224098132e-01, 2.998936318161105063e-02, 9.245380313924767002e-01, 1.994298570222236000e-01, 7.366800552480977649e-01, 5.106643027160868709e-01, 9.207942740923809044e-01, 4.181757205332312100e-01, 8.728445154291445407e-01, 9.633851936007841177e-01, 7.816264897564435543e-01, 8.582661849700918832e-01, 4.674286694993310953e-01, 1.434776671399965176e-01, 4.715239574334587624e-01, 4.237683796080935483e-01, 4.840099984088219176e-01, 4.384012343461912153e-01, 6.450580191789205831e-01, 8.711910989464527466e-01, 9.179140609476311996e-02, 3.263215529322304742e-01, 3.230871116533950982e-01, 9.580369975281920469e-01, 9.300734257129849025e-01, 1.630510312173645004e-01, 7.805955835963129807e-01, 8.090430561847644642e-01, 7.152374248454608230e-01, 4.869188853628256264e-01, 7.649278958616900770e-01, 1.144383180949043455e-01, 5.377824161382537271e-01, 2.995100425927692545e-01, 6.630850377088511050e-02, 4.940417388633088769e-01, 8.638818845297582261e-01, 9.918680871054057491e-01, 3.478953609351177478e-01, 4.526295875158595217e-01, 2.383827295980177063e-01, 7.191202725187654243e-01, 2.259808750212660700e-01, 6.112842696258790065e-01, 9.422184282921448606e-01, 3.562361307629793306e-01, 6.003547407822948934e-01, 8.973500967950022167e-01, 2.125663041458091262e-01, 3.095385140363236531e-01, 6.012178521664105491e-01, 5.352916148842006283e-01, 7.412331224425376952e-01, 1.682926935996644779e-01, 2.951198912719732448e-01, 7.582109586347400842e-01, 1.404611228748562923e-01, 5.574642725849161540e-01, 4.895069403136081965e-01, 1.785999303701339969e-01, 1.329401039739962764e-01, 8.729494708200814523e-01, 6.329724370622025198e-02, 1.142427517603542969e-01, 3.871549499699495356e-01, 7.156894920142600203e-01, 7.422119402436871960e-01, 8.200665789076719836e-01, 5.324497516050974433e-01, 8.434644856133025614e-01, 2.454711771574311086e-01, 5.573787415574117388e-01, 2.157350988358013311e-01, 3.498300117472802895e-01, 7.125448445358560298e-03, 3.161258771314184868e-01, 7.834680021684411466e-01, 3.718955769805684097e-01, 3.025699904460548706e-01, 2.310208299842673174e-01, 9.873007039329562140e-01, 1.617057421260624794e-01, 9.506372344121107876e-01, 1.677207934298330372e-01, 3.744073334266870279e-01, 1.800492462075098388e-01, 1.939106230088122329e-01, 3.733330746211031559e-01, 3.251432557627385034e-01, 1.076205970768694120e-01, 7.176648893889936431e-02, 2.099119160589595079e-01, 8.676201478697530556e-01, 1.848028666523867936e-01, 5.471882601366190313e-01, 8.520292220769356550e-01, 1.630105951054481028e-01, 4.490525469723953833e-01, 4.353253005374480011e-02, 4.865500216533337752e-01, 2.052742770413236717e-01, 6.030303108919593535e-01, 2.698630005967063150e-01, 4.979124899257769132e-01, 3.198467452114794884e-01, 3.544065423645978430e-01, 5.062501255252475074e-01, 4.821887599288864762e-02, 3.334504668143445927e-01, 5.709704277371224768e-01, 7.598195643886418438e-01, 5.411955036422259058e-01, 1.136607175544532139e-01, 5.731390128912090542e-01, 5.858307703993859139e-01, 4.666083423282086917e-01, 1.338667171827222779e-01, 8.713633670132335807e-01, 6.243558198384040470e-01, 1.938602641068542728e-02, 9.491285071166634113e-01, 7.351284526792863927e-01, 6.450385725789203883e-01, 6.205055383804133212e-02, 6.229256180389711878e-02, 9.667781021119155049e-01, 2.913925109923368728e-01, 5.443913658326705596e-01, 3.957758362869402968e-01, 2.049092380002099645e-01, 4.784649319005738199e-01, 5.225883282467590485e-01, 6.509326702545079613e-01, 2.517639816447525547e-01, 5.336230893823438182e-01, 7.270661378821501319e-01, 4.073140240063792827e-01, 7.948635105828232295e-01, 1.798368164139069747e-01, 7.711768818159895345e-01, 3.201803436981505713e-01, 9.274908997339084138e-01, 7.889941808821780977e-01, 3.210241938305002929e-02, 4.206103944241779691e-01, 5.635783779438622298e-01, 3.525062388497041677e-01, 6.132976480549050535e-01, 7.065730184571798918e-03, 6.031652878049417188e-01, 5.383980344972421062e-01, 2.857291425436735421e-01, 1.293693519122568747e-01, 6.555982116744506205e-02, 5.327010276777716102e-01, 6.362266899520729879e-01, 8.324094821713020620e-01, 3.625810813767672003e-01, 7.364122151543742723e-01, 2.202742280214905757e-01, 2.002071566836071403e-01, 7.500543265050529929e-02, 1.297259742527328008e-01, 4.852136617933804352e-01, 1.310457062634173830e-02, 7.354587386396046478e-01, 9.913762766577194352e-01, 1.738156148305238236e-01, 6.774376170215079540e-01, 3.003950920371404321e-01, 9.850314139091354004e-01, 2.363204525028220204e-01, 6.505489416044170081e-01, 3.672296989541207202e-01, 8.477480311702462190e-01, 4.228342609505404415e-01, 1.679219256388292392e-01, 1.990036775187204732e-01, 1.983061115189288515e-02, 8.286033593745986137e-01, 3.166535924950773101e-02, 3.511703053039404443e-01, 2.611131341532772487e-01, 9.824661663866857131e-01, 5.892661487165016393e-02, 8.256508048164371560e-01, 6.720007793773099536e-01, 4.123570041553689114e-01, 3.645475371158910516e-01, 2.687661658125963804e-01, 2.250745681845110202e-01, 9.068997208512777908e-01, 9.736754110351055758e-01, 5.279915628601272032e-02, 9.253700627103405019e-01, 2.624686355924266690e-01, 3.641887453662707719e-01, 9.062660373448456763e-01, 5.734433929871549651e-01, 6.685140984151645149e-01, 2.344532942868579606e-01, 7.341836162435619872e-01, 6.147702254612015249e-01, 2.567849700920377676e-01, 4.086032039955469486e-01, 3.350204753185862527e-01, 7.464931033870582100e-01, 1.688492751393790847e-01, 4.852897939299777308e-01, 9.293961549090234975e-03, 3.555104483355777667e-01, 5.651174858912215715e-01, 6.687796544560340450e-01, 9.424714538470103653e-01, 5.467364505611380654e-01, 4.317481226185619914e-01, 1.245788334199289110e-01, 1.668123138686062462e-02, 1.048237876094083310e-01, 2.570386996733011742e-01, 1.708426625555364842e-01, 6.066669254867679273e-01, 5.374387953638463111e-01, 7.807027102751896708e-01, 2.381558447895220643e-01, 6.497052131016332055e-01, 4.564431908681516048e-01, 9.984163878347751542e-02, 9.359907224383310353e-01, 9.891534676898606770e-01, 5.227852111293251197e-02, 4.899615504169120839e-01, 5.001332048824941312e-01, 7.673975951270735063e-01, 7.742123204878194054e-01, 6.280274081307576362e-01, 3.404187170376573035e-01, 8.078030608429435100e-01, 2.936462927542734525e-01, 8.188146854641985550e-01, 6.979863301296160838e-01, 7.141865713709969476e-01, 8.893823049208151588e-01, 2.468248887242447953e-01, 6.883040997217956813e-02, 2.492681888878438556e-01, 2.749377704482947049e-01, 9.452714100351311544e-01, 2.378720223621075269e-01, 5.901872666212172325e-01, 7.198568386287742052e-03, 4.760335469889425131e-01, 8.424076982128132496e-01, 2.308557363141716320e-02, 1.280409793349635561e-01, 4.078434460593570732e-01, 2.477262138582471129e-01, 6.806046141104203917e-01, 3.615084680351036694e-01, 8.664304467204932969e-01, 5.873160789183743402e-01, 3.590375687889664769e-01, 5.736980095289291315e-01, 8.679818598727979673e-01, 4.611698871790443910e-01, 1.630839701968822900e-02, 3.602376180842729037e-01, 1.788202564343425172e-01, 9.738041853113982294e-01, 7.171084366255373599e-01, 6.126414196565844739e-01, 9.772127874227991458e-04, 4.434299131425685214e-01, 2.845788460943531328e-01, 7.093647032491122717e-01, 6.185670471805592152e-01, 3.308099823238975778e-01, 3.038106610930064733e-01, 7.418731632454207414e-01, 8.469630313301501623e-01, 1.493833388984497357e-01, 2.760498756490935568e-01, 8.743109752921274236e-01, 8.864323007813664779e-01, 8.658883186956479738e-01, 4.324004368225378148e-01, 1.384916592438943383e-01, 4.648122197954418500e-02, 7.351480593099893324e-02, 5.744661715219718801e-01, 1.614946800006341610e-01, 3.464323191401127433e-01, 6.640168230441246822e-01, 1.342041444418510532e-01, 4.109972282456458847e-01, 1.053674945317465417e-01, 3.809928097180146911e-01, 4.585632602987254058e-01, 7.013677559794896377e-01, 2.959239321026639891e-01, 9.801313813484310855e-02, 9.910866979968058210e-02, 2.634357052546540401e-01, 5.922003084734605016e-01, 7.439850825927650790e-01, 2.571458015602777203e-01, 4.081631853675851129e-01, 9.948571272266359955e-01, 7.860354403850601246e-01, 6.608134156215149657e-01, 9.839499780518164984e-01, 9.249670342385858390e-01, 5.641278287105383482e-01, 6.810343505818183818e-01, 6.783578263743994530e-01, 2.667594574843039634e-01, 3.910311723053050414e-01, 2.209485343992846351e-01, 1.540843535209817650e-01, 5.978939605677485725e-01, 5.182546438223005758e-01, 8.639874970339554983e-01, 4.172541027877735287e-01, 6.368742598263820165e-01, 2.295786398996487176e-01, 4.546125221580631370e-01, 9.341810332317617149e-01, 9.349921796556430742e-01, 7.023899681154456287e-01, 9.791820924799002901e-01, 8.328956694111016024e-01, 6.673393578512013535e-01, 6.946031723537420266e-01, 5.055674389467434970e-01, 9.148699174422693092e-01, 2.238233524312585043e-01, 6.544580911528455891e-01, 4.622786573951868649e-01, 1.344442636596060725e-01, 9.565030445129046877e-01, 3.025467992871245793e-01, 6.174950269877466091e-01, 8.584910038159985213e-01, 3.989480616947653768e-01, 4.090322705807706294e-01, 8.021434247059225919e-01, 4.459182990362572374e-01, 6.976900564190382514e-01, 3.584159066129006255e-01, 7.260574904473474644e-01, 5.105163215105164021e-01, 8.635249917563870836e-01, 8.158083386506225221e-01, 4.825412900586244502e-01, 5.854038566093145990e-01, 3.139392535646755578e-01, 3.445606889039625198e-01, 4.134319418244126743e-01, 6.130096569010823337e-02, 5.818465501146293795e-01, 5.616648141264402039e-01, 3.609300395186831878e-01, 5.866051972056509634e-01, 8.384415566516145724e-01, 2.974980694770892331e-01, 6.151549914872970204e-01, 3.562443918205170368e-01, 9.410984696387169057e-01, 1.209424578701323860e-01, 8.097180500085249255e-01, 9.459321318359195097e-01, 4.975081691607242118e-01, 4.910591539941319139e-01, 3.805829794007786759e-02, 6.280473392186409765e-01, 7.128590650255968164e-01, 3.848224416842443985e-01, 2.254563265171392050e-01, 4.612587665820542249e-01, 2.387221055605281278e-02, 2.578368565673534452e-01, 3.387269205134703087e-01, 7.930580830058095443e-02, 8.547317681149221302e-01, 8.496833357381502472e-01, 6.969729642527039415e-01, 6.159737034832081515e-02, 1.783641335848656917e-01, 1.295720838523217733e-02, 6.589477779393965173e-01, 8.094822894844554417e-01, 5.414741628467258927e-01, 2.612079603260923921e-01, 2.671578103751847798e-03, 9.461063931642356151e-01, 6.100277611513521547e-01, 3.975666860197251129e-01, 8.719551136116675538e-01, 9.105780398249300189e-01, 3.955482818499367337e-02, 8.789459286962945095e-01, 5.470006647713486769e-01, 2.499079484415861474e-01, 7.656589783418413231e-02, 4.007724901562446096e-01, 4.527017482112228458e-02, 5.420405471871985181e-01, 9.651897456927094332e-01, 8.003656148727380515e-01, 9.398362536963896785e-01, 5.562955767452039124e-01, 8.444930389106458657e-01, 2.583994268936389282e-01, 2.184315243521137706e-01, 4.946448689427594969e-01, 4.564693213703298058e-01, 9.301955610092482729e-01, 1.403739207380138576e-01, 2.025430863479866783e-01, 8.012261761731769294e-01, 1.734238814379939972e-02, 6.275621579365122174e-03, 2.198704153824452279e-01, 5.305807397560600158e-01, 2.298960378614116062e-01, 9.706401898342961188e-01, 2.904802192326394472e-02, 3.775850698580844877e-01, 5.316128789806384702e-02, 3.889974826380855344e-01, 3.137762796702663337e-01, 2.861350527241194319e-01, 5.338851885782092133e-01, 7.689053676404890014e-01, 4.681243930514241702e-01, 8.900020603610157011e-01, 2.619436867806567149e-01, 3.684255371377685995e-01, 5.584190417156511543e-01, 5.894739203461893950e-01, 1.408428067401657491e-01, 6.194347166602949262e-01, 4.737257301799546738e-02, 4.029266423866778579e-01, 4.155745979842836446e-01, 7.360266842340951188e-01, 8.921896298778797529e-02, 6.114931414472462023e-01, 7.014887787438304212e-01, 3.137835306052854101e-01, 5.155568843804009260e-01, 1.779122806064518114e-01, 2.846832513620732863e-01, 8.620498702829504367e-01, 1.132661110014387962e-01, 2.758092179789058962e-01, 7.409579733709769078e-01, 4.233260727055123684e-01, 1.600918209404763592e-01, 5.799208965144514449e-01, 1.959362261819641571e-02, 4.733282090219324001e-01, 2.429817655493869966e-01, 8.530675917772082562e-01, 2.332483385547757804e-01, 3.480988746560774970e-03, 9.986392354256408144e-01, 6.562451500169598495e-02, 7.713816249089276988e-01, 3.561245442188711863e-01, 3.148836632046236872e-01, 1.375704815295816508e-01, 7.812671579997253479e-01, 1.552956497030441030e-01, 7.917244627473942753e-01, 4.561503679067611117e-01, 6.222597567387926354e-01, 5.248410452903551349e-02, 6.082080701249580057e-02, 8.172507157295043623e-01, 2.026555313966416083e-01, 9.161371922578626092e-01, 6.525528587219420196e-01, 8.065732815014692303e-01, 6.997801019495180075e-01, 1.648081525471216113e-01, 3.739177734298333444e-01, 5.692598439939173804e-01, 6.000843997326263946e-01, 2.067840010632538295e-03, 2.823406502707300758e-01, 4.900698829400949030e-01, 6.624280694212092424e-02, 5.009007932395161955e-01, 8.199109727326735486e-01, 2.021329487026094496e-01, 9.465511210438665168e-01, 2.619756104557572352e-01, 8.741516497653640805e-01, 9.352776635831349106e-01, 8.471980435791620634e-01, 4.443954273592052306e-01, 8.201945754422866885e-01, 3.359506517974662765e-02, 9.158603862767112913e-01, 8.991736647899787327e-01, 2.017845589984119115e-01, 9.858715896283589686e-01, 8.340801591967803574e-01, 8.162833098610314808e-01, 9.319412604727835836e-01, 2.851693722082383475e-01, 2.250470950578176577e-03, 4.520193520725986902e-01, 3.479606613844427043e-01, 2.729332219902452228e-01, 5.753714473447747446e-01, 4.444742882661151806e-01, 8.529692110914811609e-01, 8.772284071997512589e-01, 9.749551267666130006e-01, 4.765427438921645553e-01, 2.513581291052536804e-01, 9.813820569379142489e-01, 9.971048176469590185e-01, 9.722467636266853008e-02, 5.943055890322080925e-01, 9.828116282896783851e-01, 5.644357047792012416e-01, 7.561676081389092641e-01, 2.781938392074778665e-01, 8.173399368916247631e-01, 4.690901130179799816e-01, 6.395475498969007688e-01, 6.825617389181729555e-01, 9.806840633262186024e-01};
pfloat random_unbounded_b[12] = {-4.438700506186204819e+00, -8.739183497723428395e-01, 4.400482212895289180e-01, -2.704772218654179383e+00, 2.826592677096456896e+00, -3.563439473035713290e-01, 7.725815781187205245e-01, 7.111294246636824745e+00, 3.074709656362880850e+00, -4.188258052464925107e+00, -2.962903502701430547e+00, 2.325409366717619442e+00};
 
static char * test_random_unbounded(RInside *R){
pwork *mywork;
idxint exitflag;
 
/* print test name */
printf("================================== random_unbounded ==================================\n");
 
R->assign(random_unbounded_n, "n");
R->assign(random_unbounded_m, "m");
R->assign(random_unbounded_p, "p");
R->assign(random_unbounded_l, "l");
R->assign(random_unbounded_ncones, "ncones");
R->assign(iVec(random_unbounded_q, ILEN(random_unbounded_q)), "q");
R->assign(random_unbounded_nexc, "e");
R->assign(dVec(random_unbounded_Gpr, DLEN(random_unbounded_Gpr)), "Gpr");
R->assign(iVec(random_unbounded_Gjc, ILEN(random_unbounded_Gjc)), "Gjc");
R->assign(iVec(random_unbounded_Gir, ILEN(random_unbounded_Gir)), "Gir");
R->assign(dVec(random_unbounded_Apr, DLEN(random_unbounded_Apr)), "Apr");
R->assign(iVec(random_unbounded_Ajc, ILEN(random_unbounded_Ajc)), "Ajc");
R->assign(iVec(random_unbounded_Air, ILEN(random_unbounded_Air)), "Air");
R->assign(dVec(random_unbounded_c, DLEN(random_unbounded_c)), "c");
R->assign(dVec(random_unbounded_h, DLEN(random_unbounded_h)), "h");
R->assign(dVec(random_unbounded_b, DLEN(random_unbounded_b)), "b");
std::string fname = "random_unbounded_1.RDS";
R->assign(fname, "fname");
R->parseEvalQ("random_unbounded <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(random_unbounded, file=fname)");

/* set up data */
mywork = ECOS_setup(random_unbounded_n, random_unbounded_m, random_unbounded_p, random_unbounded_l, random_unbounded_ncones, random_unbounded_q, random_unbounded_nexc,
                    random_unbounded_Gpr, random_unbounded_Gjc, random_unbounded_Gir,
                    random_unbounded_Apr, random_unbounded_Ajc, random_unbounded_Air,
                    random_unbounded_c, random_unbounded_h, random_unbounded_b);

 if( mywork != NULL ){
/* solve */
exitflag = ECOS_solve(mywork); }
else exitflag = ECOS_FATAL;
 
/* clean up memory */
ECOS_cleanup(mywork, 0);
 
mu_assert("random_unbounded: ECOS failed to produce outputflag ECOS_DINF", exitflag == ECOS_DINF );
return 0;
}
