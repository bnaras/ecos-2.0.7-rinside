#include "ecos.h"
#include "minunit.h"
static char * test_infeasible1(RInside *R){
idxint n = 1;
idxint m = 2;
idxint p = 0;
idxint l = 2;
idxint ncones = 0;
pfloat c[1] = {-1.000000000000000000e+00};
idxint Gjc[2] = {0, 2};
idxint Gir[2] = {0, 1};
pfloat Gpr[2] = {-1.000000000000000000e+00, 1.000000000000000000e+00};
pfloat h[2] = {-2.000000000000000000e+00, 1.000000000000000000e+00};
idxint *q = NULL;
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
std::string fname = "infeasible1_1.RDS";
R->assign(fname, "fname");
R->parseEvalQ("infeasible1 <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(infeasible1, file=fname)");


/* set up data */
mywork = ECOS_setup(n, m, p, l, ncones, q, 0, Gpr, Gjc, Gir, Apr, Ajc, Air, c, h, b);

 if( mywork != NULL ){
/* solve */
exitflag = ECOS_solve(mywork); }
else exitflag = ECOS_FATAL;
 
/* clean up memory */
ECOS_cleanup(mywork, 0);
 
mu_assert("infeasible1: ECOS failed to produce outputflag PRIMAL INFEASIBLE", exitflag == ECOS_PINF );
return 0;
}
