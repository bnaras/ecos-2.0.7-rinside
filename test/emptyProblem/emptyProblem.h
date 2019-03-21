#include "ecos.h"
#include "minunit.h"
static char * test_emptyProblem(RInside *R){
idxint n = 0;
idxint m = 0;
idxint p = 0;
idxint l = 0;
idxint ncones = 0;
pfloat *c = NULL;
idxint *Gjc = NULL;
idxint *Gir = NULL;
pfloat *Gpr = NULL;
pfloat *h = NULL;
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
std::string fname = "emptyProblem_1.RDS";
R->assign(fname, "fname");
R->parseEvalQ("emptyProblem <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(emptyProblem, file=fname)");

/* set up data */
mywork = ECOS_setup(n, m, p, l, ncones, q, 0,Gpr, Gjc, Gir, Apr, Ajc, Air, c, h, b);

 if( mywork != NULL ){
/* solve */
exitflag = ECOS_solve(mywork); }
else exitflag = ECOS_FATAL;
 
/* clean up memory */
ECOS_cleanup(mywork, 0);
 
mu_assert("emptyProblem: ECOS failed to produce outputflag OPTIMAL", exitflag == ECOS_OPTIMAL );
return 0;
}
