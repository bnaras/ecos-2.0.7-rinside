#include "ecos.h"
#include "minunit.h"
static char * test_unboundedMaxSqrt(RInside *R){
idxint n = 2;
idxint m = 3;
idxint p = 0;
idxint l = 0;
idxint ncones = 1;
pfloat c[2] = {0.0, -1.000000000000000000e+00};
idxint Gjc[3] = {0, 2, 3};
idxint Gir[3] = {0, 2, 1};
pfloat Gpr[3] = {-1.000000000000000000e+00, -1.000000000000000000e+00, -2.000000000000000000e+00};
pfloat h[3] = {1.000000000000000000e+00, 0.0, -1.000000000000000000e+00};
idxint q[1] = {3};
idxint *Ajc = NULL;
idxint *Air = NULL;
pfloat *Apr = NULL;
pfloat *b = NULL;
 
pwork *mywork;
idxint exitflag;
 
R->assign(n, "n");
R->assign(m, "m");
R->assign(p, "p");
R->assign(l, "l");
R->assign(ncones, "ncones");
R->assign(iVec(q, ILEN(q)), "q");
R->assign(0, "e");
R->assign(dVec(Gpr, DLEN(Gpr)), "Gpr");
R->assign(iVec(Gjc, ILEN(Gjc)), "Gjc");
R->assign(iVec(Gir, ILEN(Gir)), "Gir");
R->assign(dVec(Apr, DLEN(Apr)), "Apr");
R->assign(iVec(Ajc, ILEN(Ajc)), "Ajc");
R->assign(iVec(Air, ILEN(Air)), "Air");
R->assign(dVec(c, DLEN(c)), "c");
R->assign(dVec(h, DLEN(h)), "h");
R->assign(dVec(b, DLEN(b)), "b");
std::string fname = "unboundedMaxSqrt_1.RDS";
R->assign(fname, "fname");
R->parseEvalQ("unboundedMaxSqrt <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(unboundedMaxSqrt, file=fname)");

/* set up data */
mywork = ECOS_setup(n, m, p, l, ncones, q, 0, Gpr, Gjc, Gir, Apr, Ajc, Air, c, h, b);

 if( mywork != NULL ){
/* solve */
exitflag = ECOS_solve(mywork); }
else exitflag = ECOS_FATAL;
 
/* clean up memory */
ECOS_cleanup(mywork, 0);
 
mu_assert("unboundedMaxSqrt: ECOS failed to produce outputflag DUAL INFEASIBLE", exitflag == ECOS_DINF );
return 0;
}
