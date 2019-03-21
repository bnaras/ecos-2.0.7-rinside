#include "ecos.h"
#include "minunit.h"

static pfloat feas_Gx[2] = {1, -1};
static idxint feas_Gp[2] = {0, 2};
static idxint feas_Gi[2] = {0, 1};

static pfloat feas_c[1] = {0};
static pfloat feas_h[2] = {1, 0};

static char * test_feas(RInside *R)
{
    /**
     * minimize 0
     * s.t. 0 <= x <= 1
     */
    pwork *mywork;
    idxint exitflag;

R->assign(1, "n");
R->assign(2, "m");
R->assign(0, "p");
R->assign(2, "l");
R->assign(0, "ncones");
R->assign(iVec(NULL, ILEN(NULL)), "q");
R->assign(0, "e");
R->assign(dVec(feas_Gx, DLEN(feas_Gx)), "Gpr");
R->assign(iVec(feas_Gp, ILEN(feas_Gp)), "Gjc");
R->assign(iVec(feas_Gi, ILEN(feas_Gi)), "Gir");
R->assign(dVec(NULL, DLEN(NULL)), "Apr");
R->assign(iVec(NULL, ILEN(NULL)), "Ajc");
R->assign(iVec(NULL, ILEN(NULL)), "Air");
R->assign(dVec(feas_c, DLEN(feas_c)), "c");
R->assign(dVec(feas_h, DLEN(feas_h)), "h");
R->assign(dVec(NULL, DLEN(NULL)), "b");
std::string fname = "feas_1.RDS";
R->assign(fname, "fname");
R->parseEvalQ("feas <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(feas, file=fname)");

    /* set up data */
    mywork = ECOS_setup(1, 2, 0,
        2, 0, NULL, 0,
        feas_Gx, feas_Gp, feas_Gi,
        NULL, NULL, NULL,
        feas_c, feas_h, NULL);

    if( mywork != NULL ){
        /* solve */
        exitflag = ECOS_solve(mywork); 
    }
    else exitflag = ECOS_FATAL;
        
    /* clean up memory */
    ECOS_cleanup(mywork, 0);
    
    mu_assert("feas-test: ECOS failed to produce outputflag OPTIMAL", exitflag == ECOS_OPTIMAL );
    return 0;
}
