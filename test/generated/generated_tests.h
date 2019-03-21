#include "ecos.h"
#include "minunit.h"
#include "norm/norm.h"
#include "quad_over_lin/quad_over_lin.h"
#include "sq_norm/sq_norm.h"
#include "sum_sq/sum_sq.h"
#include "inv_pos/inv_pos.h"
#include "qcml_utils.h"

static char * test_norm(RInside *R)
{

    pwork *mywork;
    idxint exitflag;
    qc_socp *data;

    data = qc_norm2socp();

R->assign(data->n, "n");
R->assign(data->m, "m");
R->assign(data->p, "p");
R->assign(data->l, "l");
R->assign(data->nsoc, "ncones");
R->assign(iVec(data->q, data->nsoc), "q");
R->assign(0, "e");
R->assign(dVec(data->Gx, data->Gnnz), "Gpr");
 printf("Got past Gnnz\n");
 R->assign(iVec(data->Gp, (data->n) + 1), "Gjc");
 printf("Got past Gp\n"); 
R->assign(iVec(data->Gi, data->Gnnz), "Gir");
 printf("Got past Gi\n");  
R->assign(dVec(data->Ax, data->Annz), "Apr");
 printf("Got past Annz\n"); 
R->assign(iVec(data->Ap, 0), "Ajc");
 printf("Got past Ap\n"); 
R->assign(iVec(data->Ai, data->Annz), "Air");
 printf("Got past Ai\n"); 
R->assign(dVec(data->c, data->n), "c");
 printf("Got past c\n"); 
R->assign(dVec(data->h, data->m), "h");
 printf("Got past h\n"); 
R->assign(dVec(data->b, data->p), "b");
 printf("Got past b\n"); 
std::string fname = "generated_tests_1.RDS";
R->assign(fname, "fname");
R->parseEvalQ("generated_tests <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(generated_tests, file=fname)");
    
    /* set up data */
    mywork = ECOS_setup(data->n, data->m, data->p,
        data->l, data->nsoc, data->q, 0,
        data->Gx, data->Gp, data->Gi,
        data->Ax, data->Ap, data->Ai,
        data->c, data->h, data->b);

    if( mywork != NULL ){
        /* solve */
        exitflag = ECOS_solve(mywork);
    }
    else exitflag = ECOS_FATAL;

    /* clean up memory */
    ECOS_cleanup(mywork, 0);
    qc_socp_free(data);

    mu_assert("quadratics-norm-test: ECOS failed to produce output flag OPTIMAL", exitflag == ECOS_OPTIMAL );
    return 0;
}

static char * test_quad_over_lin(RInside *R)
{

    pwork *mywork;
    idxint exitflag;
    qc_socp *data;

    data = qc_quad_over_lin2socp();

R->assign(data->n, "n");
R->assign(data->m, "m");
R->assign(data->p, "p");
R->assign(data->l, "l");
R->assign(data->nsoc, "ncones");
R->assign(iVec(data->q, data->nsoc), "q");
R->assign(0, "e");
R->assign(dVec(data->Gx, data->Gnnz), "Gpr");
R->assign(iVec(data->Gp, (data->n) + 1), "Gjc");
R->assign(iVec(data->Gi, data->Gnnz), "Gir");
R->assign(dVec(data->Ax, data->Annz), "Apr");
R->assign(iVec(data->Ap, 0), "Ajc");
R->assign(iVec(data->Ai, data->Annz), "Air");
R->assign(dVec(data->c, data->n), "c");
R->assign(dVec(data->h, data->m), "h");
R->assign(dVec(data->b, data->p), "b");
std::string fname = "generated_tests_2.RDS";
R->assign(fname, "fname");
R->parseEvalQ("generated_tests <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(generated_tests, file=fname)");
    
    /* set up data */
    mywork = ECOS_setup(data->n, data->m, data->p,
        data->l, data->nsoc, data->q, 0,
        data->Gx, data->Gp, data->Gi,
        data->Ax, data->Ap, data->Ai,
        data->c, data->h, data->b);

    if( mywork != NULL ){
        /* solve */
        exitflag = ECOS_solve(mywork);
    }
    else exitflag = ECOS_FATAL;

    /* clean up memory */
    ECOS_cleanup(mywork, 0);
    qc_socp_free(data);

    mu_assert("quadratics-quad-over-lin-test: ECOS failed to produce output flag OPTIMAL", exitflag == ECOS_OPTIMAL );
    return 0;
}

static char * test_sq_norm(RInside *R)
{

    pwork *mywork;
    idxint exitflag;
    qc_socp *data;

    data = qc_sq_norm2socp();

R->assign(data->n, "n");
R->assign(data->m, "m");
R->assign(data->p, "p");
R->assign(data->l, "l");
R->assign(data->nsoc, "ncones");
R->assign(iVec(data->q, data->nsoc), "q");
R->assign(0, "e");
R->assign(dVec(data->Gx, data->Gnnz), "Gpr");
R->assign(iVec(data->Gp, (data->n) + 1), "Gjc");
R->assign(iVec(data->Gi, data->Gnnz), "Gir");
R->assign(dVec(data->Ax, data->Annz), "Apr");
R->assign(iVec(data->Ap, 0), "Ajc");
R->assign(iVec(data->Ai, data->Annz), "Air");
R->assign(dVec(data->c, data->n), "c");
R->assign(dVec(data->h, data->m), "h");
R->assign(dVec(data->b, data->p), "b");
std::string fname = "generated_tests_3.RDS";
R->assign(fname, "fname");
R->parseEvalQ("generated_tests <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(generated_tests, file=fname)");
    
    /* set up data */
    mywork = ECOS_setup(data->n, data->m, data->p,
        data->l, data->nsoc, data->q, 0,
        data->Gx, data->Gp, data->Gi,
        data->Ax, data->Ap, data->Ai,
        data->c, data->h, data->b);

    if( mywork != NULL ){
        /* solve */
        exitflag = ECOS_solve(mywork);
    }
    else exitflag = ECOS_FATAL;

    /* clean up memory */
    ECOS_cleanup(mywork, 0);
    qc_socp_free(data);

    mu_assert("quadratics-sq-norm-test: ECOS failed to produce output flag OPTIMAL", exitflag == ECOS_OPTIMAL );
    return 0;
}

static char * test_sum_sq(RInside *R)
{

    pwork *mywork;
    idxint exitflag;
    qc_socp *data;

    data = qc_sum_sq2socp();

R->assign(data->n, "n");
R->assign(data->m, "m");
R->assign(data->p, "p");
R->assign(data->l, "l");
R->assign(data->nsoc, "ncones");
R->assign(iVec(data->q, data->nsoc), "q");
R->assign(0, "e");
R->assign(dVec(data->Gx, data->Gnnz), "Gpr");
R->assign(iVec(data->Gp, (data->n) + 1), "Gjc");
R->assign(iVec(data->Gi, data->Gnnz), "Gir");
R->assign(dVec(data->Ax, data->Annz), "Apr");
R->assign(iVec(data->Ap, 0), "Ajc");
R->assign(iVec(data->Ai, data->Annz), "Air");
R->assign(dVec(data->c, data->n), "c");
R->assign(dVec(data->h, data->m), "h");
R->assign(dVec(data->b, data->p), "b");
std::string fname = "generated_tests_4.RDS";
R->assign(fname, "fname");
R->parseEvalQ("generated_tests <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(generated_tests, file=fname)");

    /* set up data */
    mywork = ECOS_setup(data->n, data->m, data->p,
        data->l, data->nsoc, data->q, 0,
        data->Gx, data->Gp, data->Gi,
        data->Ax, data->Ap, data->Ai,
        data->c, data->h, data->b);

    if( mywork != NULL ){
        /* solve */
        exitflag = ECOS_solve(mywork);
    }
    else exitflag = ECOS_FATAL;

    /* clean up memory */
    ECOS_cleanup(mywork, 0);
    qc_socp_free(data);

    mu_assert("quadratics-sum-sq-test: ECOS failed to produce output flag OPTIMAL", exitflag == ECOS_OPTIMAL );
    return 0;
}

static char * test_inv_pos(RInside *R)
{

    pwork *mywork;
    idxint exitflag;
    qc_socp *data;

    data = qc_inv_pos2socp();

R->assign(data->n, "n");
R->assign(data->m, "m");
R->assign(data->p, "p");
R->assign(data->l, "l");
R->assign(data->nsoc, "ncones");
R->assign(iVec(data->q, data->nsoc), "q");
R->assign(0, "e");
R->assign(dVec(data->Gx, data->Gnnz), "Gpr");
R->assign(iVec(data->Gp, (data->n) + 1), "Gjc");
R->assign(iVec(data->Gi, data->Gnnz), "Gir");
R->assign(dVec(data->Ax, data->Annz), "Apr");
R->assign(iVec(data->Ap, 0), "Ajc");
R->assign(iVec(data->Ai, data->Annz), "Air");
R->assign(dVec(data->c, data->n), "c");
R->assign(dVec(data->h, data->m), "h");
R->assign(dVec(data->b, data->p), "b");
std::string fname = "generated_tests_5.RDS";
R->assign(fname, "fname");
R->parseEvalQ("generated_tests <- list(n=n, m=m, p=p, l=l, ncones=ncones, q=q, e=e, Gpr=Gpr, Gjc=Gjc, Gir=Gir, Apr=Apr, Ajc=Ajc, Air=Air, c=c, h=h, b=b)");
R->parseEvalQ("saveRDS(generated_tests, file=fname)");

    
    /* set up data */
    mywork = ECOS_setup(data->n, data->m, data->p,
        data->l, data->nsoc, data->q, 0, 
        data->Gx, data->Gp, data->Gi,
        data->Ax, data->Ap, data->Ai,
        data->c, data->h, data->b);
    if( mywork != NULL ){
        /* solve */
        exitflag = ECOS_solve(mywork);
    }
    else exitflag = ECOS_FATAL;

    /* clean up memory */
    ECOS_cleanup(mywork, 0);
    qc_socp_free(data);

    mu_assert("inv-pos-test: ECOS failed to produce at least something close to OPTIMAL", exitflag == ECOS_OPTIMAL+ECOS_INACC_OFFSET || exitflag == ECOS_OPTIMAL );
    return 0;
}

