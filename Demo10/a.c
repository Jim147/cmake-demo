#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
int main (void)
{
    double data[] = { 1.0, 0.44, 0.29, 0.33,
                      0.44, 1.0, 0.35, 0.32,
                      0.29, 0.35, 1.0, 0.60,
                      0.33, 0.32, 0.60, 1.0 };
    
    gsl_matrix_view m = gsl_matrix_view_array (data, 4, 4);

    gsl_vector *eval = gsl_vector_alloc (4);
    gsl_matrix *evec = gsl_matrix_alloc (4, 4);
    gsl_eigen_symmv_workspace * w = gsl_eigen_symmv_alloc (4);

    gsl_eigen_symmv (&m.matrix, eval, evec, w);
    gsl_eigen_symmv_free (w);
    gsl_eigen_symmv_sort (eval, evec, GSL_EIGEN_SORT_ABS_ASC);

    {
        int i;
        for (i = 0; i < 4; i++)
        {
            double eval_i = gsl_vector_get (eval, i);
            gsl_vector_view evec_i = gsl_matrix_column (evec, i);
            printf ("eigenvalue = %g\n", eval_i);
            printf ("eigenvector = \n");
            gsl_vector_fprintf (stdout, &evec_i.vector, "%g");
        }
    }
    gsl_vector_free (eval);
    gsl_matrix_free (evec);
    return 0;
}