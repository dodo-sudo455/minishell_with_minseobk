#include "main.h"
t_error geterr(t_ctx *c_ref) { (void)c_ref; return ERROR_OK; }
t_error seterr(t_ctx *c_ref, t_error err) { (void)c_ref; return err; }
t_ctx ctx_make(void) { t_ctx c; ft_memset(&c, 0, sizeof(c)); return c; }
t_error ctx_init(t_ctx *c_ref, char **envp) { (void)c_ref; (void)envp; return ERROR_OK; }
char *ctx_expand(const t_ctx *c_ref, const char *key) { (void)c_ref; (void)key; return NULL; }
t_error parse_expand(t_ctx *c_ref, t_lst *toklst_ref) { (void)c_ref; (void)toklst_ref; return ERROR_OK; }
t_error parse_quote(t_ctx *c_ref, t_lst *toklst_ref) { (void)c_ref; (void)toklst_ref; return ERROR_OK; }
