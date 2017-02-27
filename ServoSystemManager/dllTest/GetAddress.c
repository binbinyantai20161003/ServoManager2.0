#include "SevObjMang.h"
#include "SevTaskSched.h"
#include "SevAuxFunc.h"
#include <stdio.h>
#include <stdlib.h>

#define VNAME(name) (#name)

int writeAddressFile()
{
  unsigned int tmp;
  unsigned int i;
  FILE *fp;
  fp = fopen("Addr.txt", "w+");
  if (NULL == fp)
  {
      return -1;
  }

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->act_on))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->act_on));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->sec_on))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->sec_on));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->sof_st_on))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->sof_st_on));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->serv_ready))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->serv_ready));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->curr_id))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->curr_id));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->cmd_id))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->cmd_id));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->curr_state))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->curr_state));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->idr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->idr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->iqr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->iqr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->spdr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->spdr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->posr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->posr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->udr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->udr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->uqr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->uqr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->uar_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->uar_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->ubr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->ubr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->ucr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->ucr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->pos_adjr_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->pos_adjr_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->act_on_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->act_on_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->cmd_id_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->cmd_id_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd->ref_upd_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd->ref_upd_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_chd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->prm.vol_mode))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->prm.vol_mode));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->prm.spd_stop_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->prm.spd_stop_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->id_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->id_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->iq_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->iq_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->spd_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->spd_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->pos_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->pos_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->ud_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->ud_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->uq_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->uq_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->ua_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->ua_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->ub_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->ub_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->uc_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->uc_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->pos_adj_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->pos_adj_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->pwm_en_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->pwm_en_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->clr_sts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->clr_sts));

  tmp = (((unsigned int)(&(gSevDrv.sev_task->idle_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task->idle_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_task))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.prm.axis_sn))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.prm.axis_sn));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Irat_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Irat_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Imax_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Imax_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Sct_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Sct_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Srat_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Srat_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Nos_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Nos_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Tqr_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Tqr_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.PPN_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.PPN_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Vmax_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Vmax_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.PHIm_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.PHIm_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Kti))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Kti));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Ldm_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Ldm_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Lqm_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Lqm_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Rm_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Rm_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Jm_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Jm_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Jrat_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Jrat_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Fm_1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Fm_1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.PHIc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.PHIc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.LDc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.LDc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.LQc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.LQc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.Rc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.Rc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.TS))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.TS));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot.DT))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot.DT));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.mot))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.mot));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kia))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kia));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kib))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kib));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kic))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kic));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.ia_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.ia_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.ib_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.ib_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.ic_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.ic_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.isamp_pha_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.isamp_pha_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kvdc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kvdc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kv_uv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kv_uv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kv_vw))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kv_vw));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.vdc_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.vdc_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.vuv_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.vuv_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.vvw_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.vvw_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kpre))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kpre));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.pre_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.pre_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.klpf_pre_fb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.klpf_pre_fb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kt_rtf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kt_rtf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.kt_igbt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.kt_igbt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.t_rtf_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.t_rtf_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm.t_igbt_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm.t_igbt_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.ia))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.ia));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.ib))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.ib));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.ic))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.ic));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.ia_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.ia_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.ib_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.ib_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.ic_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.ic_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.curr_adj_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.curr_adj_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.curr_adj_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.curr_adj_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.vdc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.vdc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.v_uv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.v_uv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.v_vw))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.v_vw));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.vdc_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.vdc_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.v_uv_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.v_uv_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.v_vw_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.v_vw_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.pre))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.pre));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.pre_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.pre_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.pre_adj_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.pre_adj_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.pre_adj_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.pre_adj_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.t_rtf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.t_rtf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.t_igbt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.t_igbt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.t_rtf_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.t_rtf_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.t_igbt_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.t_igbt_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_ia))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_ia));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_ib))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_ib));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_ic))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_ic));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_vdc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_vdc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_vuv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_vuv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_vvw))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_vvw));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_pre))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_pre));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_trtf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_trtf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc.s_tigbt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc.s_tigbt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.adc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.adc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.coder_typ_3))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.coder_typ_3));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.seq_dir))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.seq_dir));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.acc_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.acc_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.klpf_spd_fb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.klpf_spd_fb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.kspd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.kspd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.kphc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.kphc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.pos_ofst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.pos_ofst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.line_num_3))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.line_num_3));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.kpos_to_ephi))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.kpos_to_ephi));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm.rline_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm.rline_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.spd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.spd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dif_spd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dif_spd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.mot_spd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.mot_spd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.acc_pos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.acc_pos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[4]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[4]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[5]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[5]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[6]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[6]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[7]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[7]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpos_buf[8]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpos_buf[8]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pos_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pos_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pos_cnt_last))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pos_cnt_last));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pos_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pos_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pos_lst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pos_lst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pos_elec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pos_elec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pos_elec2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pos_elec2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.dpulr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.dpulr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pulr_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pulr_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pulr_cnt_last))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pulr_cnt_last));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv.pulr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv.pulr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.rsv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.rsv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv.prm.max_duty))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv.prm.max_duty));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv.prm.frq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv.prm.frq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv.prm.oc_duty))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv.prm.oc_duty));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv.prm.ready_times))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv.prm.ready_times));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv.ready_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv.ready_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv.ready_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv.ready_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.drv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.drv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.alm_mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.alm_mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.alm_mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.alm_mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.alm_mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.alm_mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.oc_tf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.oc_tf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.ol_tf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.ol_tf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.kg_oc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.kg_oc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.kg_ol))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.kg_ol));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.kcur_to_nom))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.kcur_to_nom));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.kf_oc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.kf_oc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.kf_ol))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.kf_ol));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.ol_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.ol_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.oc_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.oc_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.k_lpf_vdc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.k_lpf_vdc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.vdc_ulim_2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.vdc_ulim_2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.vdc_llim_2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.vdc_llim_2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.bk_ulim_2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.bk_ulim_2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.bk_llim_2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.bk_llim_2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.mot_tp_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.mot_tp_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.igbt_tp_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.igbt_tp_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.k_lpf_ot))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.k_lpf_ot));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.fant_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.fant_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.fant_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.fant_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.os_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.os_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.os_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.os_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.k_lpf_spd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.k_lpf_spd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.pre_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.pre_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.peak_curr_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.peak_curr_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.brake_en))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.brake_en));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.sinc_ipeak_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.sinc_ipeak_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm.sinc_ipeak_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm.sinc_ipeak_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.alm_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.alm_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.alm_code.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.alm_code.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.alm_code.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.alm_code.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.alm_code))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.alm_code));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.ol_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.ol_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.oc_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.oc_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.vdc_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.vdc_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.bk_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.bk_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.t_igbt_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.t_igbt_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.t_mot_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.t_mot_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro.spd_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro.spd_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pro))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pro));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.k_lpf_vbus))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.k_lpf_vbus));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.k2_lpf_vbus))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.k2_lpf_vbus));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.dv_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.dv_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.soft_on_thd_2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.soft_on_thd_2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.soft_off_thd_2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.soft_off_thd_2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.dyn_brak_wait_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.dyn_brak_wait_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.dyn_brak_hold_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.dyn_brak_hold_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.out_brak_delay_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.out_brak_delay_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.out_brak_wait_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.out_brak_wait_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.out_brake_hold_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.out_brake_hold_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.dyn_brake_lag_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.dyn_brake_lag_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.out_brake_lag_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.out_brake_lag_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.out_brake_spd_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.out_brake_spd_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.db_curr_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.db_curr_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.fnc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.fnc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.tic))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.tic));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.kpc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.kpc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.kic))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.kic));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.co_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.co_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.co_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.co_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.ci_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.ci_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm.ci_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm.ci_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.vbus))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.vbus));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.vbus2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.vbus2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.soft_start_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.soft_start_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.safe_seq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.safe_seq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.db_mod))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.db_mod));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.db_on_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.db_on_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.dyn_brak_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.dyn_brak_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.out_brak_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.out_brak_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.delay_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.delay_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.idb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.idb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.idb_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.idb_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.udb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.udb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.idb_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.idb_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr.idbi_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr.idbi_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.pwr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.pwr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm.tfd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm.tfd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm.tfq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm.tfq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm.kfd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm.kfd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm.kfq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm.kfq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.xd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.xd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf.xq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf.xq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.lpf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.lpf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.Tid_4))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.Tid_4));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.Tiq_4))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.Tiq_4));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.fnd_4))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.fnd_4));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.fnq_4))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.fnq_4));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.kpd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.kpd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.kpq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.kpq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.kid))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.kid));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.kiq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.kiq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.do_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.do_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.do_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.do_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.qo_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.qo_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.qo_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.qo_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.di_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.di_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.di_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.di_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.qi_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.qi_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm.qi_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm.qi_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.id))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.id));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.iq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.iq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.id_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.id_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.iq_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.iq_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.ud))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.ud));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.uq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.uq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.id_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.id_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.iq_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.iq_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.idi_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.idi_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl.iqi_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl.iqi_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ctl))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ctl));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.prm.kt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.prm.kt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.mech_phi))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.mech_phi));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.e_phi))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.e_phi));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.sin_ph))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.sin_ph));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.cos_ph))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.cos_ph));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.sin_ph2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.sin_ph2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.cos_ph2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.cos_ph2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.sin_ph3))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.sin_ph3));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr.cos_ph3))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr.cos_ph3));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dqtr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dqtr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.ov_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.ov_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.ov_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.ov_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.max_duty))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.max_duty));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.half_duty))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.half_duty));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.kmodul))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.kmodul));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.modul_duty))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.modul_duty));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.spwm_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.spwm_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm.spwm_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm.spwm_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.va))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.va));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.vb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.vb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.vc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.vc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.da))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.da));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.db))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.db));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.dc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.dc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.ta))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.ta));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.tb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.tb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.tc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.tc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.volt_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.volt_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.theta_e))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.theta_e));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm.sec_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm.sec_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ovm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ovm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop.prm.cur_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop.prm.cur_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop.vphi))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop.vphi));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop.vlwd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop.vlwd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop.vlwq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop.vlwq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop.vrd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop.vrd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop.vrq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop.vrq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dcop))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dcop));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm.ip_sw))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm.ip_sw));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm.ip_tra))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm.ip_tra));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm.k_ondv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm.k_ondv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm.ondv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm.ondv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm.od_lvl))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm.od_lvl));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm.dt_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm.dt_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm.dt_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm.dt_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.dcu))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.dcu));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.dcv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.dcv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp.dcw))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp.dcw));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.dtcp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.dtcp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.kp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.kp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.ki))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.ki));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.fwo_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.fwo_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.fwo_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.fwo_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.fwi_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.fwi_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.fwi_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.fwi_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.k_lpf_udq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.k_lpf_udq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm.v_sat))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm.v_sat));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.ud))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.ud));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.uq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.uq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.v_r))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.v_r));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.idc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.idc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.fw_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.fw_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.fwi_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.fwi_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.id_max))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.id_max));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk.idi_max))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk.idi_max));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.fwk))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.fwk));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ud))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ud));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.uq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.uq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ua))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ua));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.ub))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.ub));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur.uc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur.uc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->cur))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->cur));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.un_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.un_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.tf_rmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.tf_rmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.delt_rmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.delt_rmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm.prmf[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm.prmf[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.var[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.var[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf.rmp_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf.rmp_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.vrf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.vrf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.kvi_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.kvi_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.fn_fst_5))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.fn_fst_5));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.ti_fst_5))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.ti_fst_5));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.fn_sec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.fn_sec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.ti_sec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.ti_sec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.abs_rat_5))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.abs_rat_5));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.pos_rat_5))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.pos_rat_5));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.neg_rat_5))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.neg_rat_5));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.kv_fst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.kv_fst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.ki_fst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.ki_fst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.kv_sec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.kv_sec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.ki_sec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.ki_sec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.kv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.kv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.ki))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.ki));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.vo_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.vo_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.vo_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.vo_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.vi_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.vi_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm.vi_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm.vi_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.spd_fb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.spd_fb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.spd_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.spd_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.spd_err))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.spd_err));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.iu[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.iu[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.iu[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.iu[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.iu[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.iu[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.xwkp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.xwkp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.xwki))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.xwki));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl.tqr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl.tqr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.ctl))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.ctl));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.un_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.un_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[4]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[4]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[5]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[5]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm.prmf[6]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm.prmf[6]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[4]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[4]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[5]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[5]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf.var[6]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf.var[6]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel.trf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel.trf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->vel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->vel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.un_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.un_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.maf_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.maf_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fit_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fit_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fn1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fn1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].tf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].tf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fn2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fn2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].qx2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].qx2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].fn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].qx_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].qx_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kn_nch))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kn_nch));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kf2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2].kfn_ad[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm.prmf[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm.prmf[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.idx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.idx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.ksub))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.ksub));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.sumx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.sumx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.remx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.remx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.zcntx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.zcntx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[4]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[4]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[5]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[5]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[6]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[6]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[7]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[7]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[8]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[8]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[9]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[9]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[10]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[10]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[11]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[11]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[12]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[12]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[13]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[13]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[14]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[14]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[15]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[15]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[16]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[16]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[17]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[17]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[18]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[18]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[19]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[19]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[20]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[20]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[21]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[21]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[22]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[22]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[23]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[23]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[24]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[24]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[25]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[25]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[26]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[26]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[27]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[27]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[28]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[28]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[29]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[29]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[30]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[30]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[31]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[31]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[32]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[32]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[33]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[33]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[34]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[34]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[35]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[35]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[36]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[36]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[37]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[37]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[38]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[38]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[39]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[39]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[40]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[40]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[41]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[41]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[42]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[42]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[43]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[43]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[44]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[44]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[45]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[45]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[46]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[46]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[47]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[47]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[48]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[48]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[49]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[49]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[50]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[50]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[51]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[51]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[52]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[52]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[53]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[53]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[54]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[54]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[55]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[55]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[56]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[56]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[57]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[57]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[58]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[58]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[59]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[59]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[60]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[60]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[61]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[61]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[62]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[62]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[63]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[63]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[64]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[64]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[65]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[65]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[66]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[66]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[67]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[67]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[68]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[68]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[69]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[69]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[70]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[70]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[71]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[71]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[72]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[72]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[73]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[73]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[74]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[74]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[75]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[75]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[76]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[76]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[77]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[77]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[78]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[78]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[79]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[79]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[80]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[80]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[81]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[81]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[82]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[82]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[83]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[83]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[84]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[84]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[85]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[85]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[86]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[86]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[87]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[87]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[88]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[88]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[89]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[89]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[90]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[90]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[91]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[91]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[92]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[92]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[93]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[93]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[94]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[94]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[95]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[95]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[96]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[96]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[97]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[97]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[98]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[98]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[99]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[99]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[100]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[100]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[101]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[101]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[102]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[102]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[103]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[103]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[104]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[104]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[105]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[105]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[106]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[106]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[107]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[107]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[108]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[108]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[109]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[109]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[110]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[110]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[111]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[111]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[112]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[112]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[113]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[113]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[114]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[114]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[115]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[115]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[116]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[116]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[117]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[117]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[118]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[118]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[119]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[119]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[120]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[120]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[121]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[121]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[122]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[122]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[123]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[123]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[124]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[124]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[125]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[125]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[126]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[126]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[127]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[127]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[128]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[128]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[129]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[129]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[130]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[130]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[131]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[131]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[132]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[132]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[133]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[133]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[134]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[134]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[135]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[135]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[136]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[136]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[137]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[137]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[138]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[138]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[139]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[139]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[140]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[140]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[141]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[141]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[142]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[142]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[143]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[143]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[144]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[144]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[145]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[145]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[146]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[146]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[147]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[147]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[148]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[148]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[149]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[149]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[150]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[150]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[151]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[151]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[152]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[152]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[153]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[153]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[154]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[154]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[155]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[155]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[156]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[156]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[157]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[157]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[158]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[158]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[159]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[159]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[160]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[160]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[161]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[161]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[162]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[162]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[163]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[163]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[164]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[164]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[165]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[165]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[166]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[166]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[167]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[167]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[168]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[168]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[169]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[169]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[170]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[170]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[171]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[171]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[172]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[172]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[173]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[173]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[174]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[174]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[175]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[175]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[176]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[176]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[177]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[177]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[178]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[178]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[179]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[179]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[180]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[180]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[181]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[181]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[182]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[182]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[183]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[183]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[184]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[184]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[185]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[185]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[186]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[186]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[187]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[187]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[188]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[188]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[189]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[189]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[190]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[190]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[191]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[191]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[192]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[192]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[193]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[193]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[194]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[194]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[195]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[195]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[196]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[196]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[197]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[197]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[198]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[198]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[199]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[199]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[200]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[200]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[201]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[201]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[202]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[202]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[203]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[203]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[204]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[204]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[205]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[205]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[206]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[206]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[207]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[207]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[208]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[208]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[209]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[209]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[210]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[210]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[211]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[211]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[212]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[212]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[213]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[213]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[214]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[214]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[215]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[215]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[216]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[216]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[217]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[217]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[218]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[218]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[219]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[219]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[220]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[220]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[221]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[221]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[222]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[222]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[223]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[223]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[224]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[224]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[225]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[225]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[226]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[226]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[227]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[227]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[228]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[228]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[229]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[229]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[230]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[230]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[231]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[231]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[232]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[232]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[233]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[233]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[234]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[234]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[235]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[235]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[236]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[236]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[237]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[237]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[238]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[238]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[239]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[239]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[240]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[240]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[241]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[241]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[242]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[242]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[243]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[243]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[244]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[244]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[245]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[245]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[246]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[246]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[247]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[247]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[248]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[248]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[249]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[249]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[250]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[250]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[251]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[251]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[252]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[252]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[253]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[253]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[254]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[254]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[255]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[255]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[256]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[256]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[257]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[257]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[258]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[258]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[259]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[259]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[260]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[260]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[261]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[261]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[262]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[262]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[263]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[263]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[264]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[264]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[265]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[265]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[266]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[266]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[267]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[267]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[268]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[268]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[269]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[269]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[270]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[270]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[271]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[271]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[272]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[272]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[273]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[273]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[274]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[274]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[275]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[275]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[276]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[276]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[277]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[277]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[278]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[278]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[279]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[279]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[280]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[280]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[281]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[281]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[282]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[282]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[283]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[283]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[284]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[284]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[285]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[285]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[286]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[286]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[287]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[287]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[288]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[288]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[289]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[289]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[290]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[290]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[291]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[291]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[292]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[292]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[293]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[293]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[294]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[294]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[295]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[295]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[296]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[296]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[297]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[297]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[298]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[298]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[299]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[299]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[300]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[300]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[301]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[301]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[302]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[302]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[303]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[303]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[304]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[304]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[305]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[305]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[306]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[306]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[307]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[307]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[308]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[308]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[309]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[309]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[310]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[310]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[311]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[311]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[312]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[312]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[313]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[313]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[314]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[314]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[315]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[315]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[316]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[316]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[317]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[317]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[318]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[318]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[319]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[319]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[320]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[320]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[321]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[321]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[322]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[322]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[323]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[323]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[324]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[324]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[325]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[325]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[326]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[326]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[327]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[327]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[328]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[328]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[329]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[329]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[330]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[330]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[331]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[331]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[332]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[332]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[333]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[333]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[334]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[334]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[335]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[335]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[336]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[336]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[337]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[337]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[338]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[338]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[339]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[339]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[340]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[340]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[341]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[341]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[342]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[342]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[343]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[343]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[344]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[344]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[345]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[345]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[346]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[346]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[347]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[347]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[348]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[348]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[349]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[349]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[350]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[350]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[351]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[351]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[352]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[352]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[353]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[353]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[354]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[354]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[355]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[355]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[356]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[356]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[357]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[357]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[358]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[358]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[359]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[359]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[360]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[360]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[361]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[361]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[362]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[362]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[363]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[363]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[364]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[364]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[365]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[365]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[366]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[366]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[367]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[367]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[368]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[368]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[369]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[369]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[370]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[370]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[371]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[371]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[372]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[372]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[373]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[373]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[374]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[374]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[375]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[375]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[376]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[376]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[377]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[377]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[378]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[378]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[379]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[379]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[380]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[380]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[381]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[381]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[382]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[382]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[383]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[383]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[384]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[384]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[385]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[385]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[386]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[386]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[387]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[387]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[388]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[388]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[389]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[389]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[390]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[390]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[391]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[391]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[392]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[392]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[393]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[393]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[394]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[394]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[395]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[395]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[396]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[396]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[397]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[397]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[398]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[398]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[399]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[399]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[400]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[400]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[401]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[401]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[402]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[402]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[403]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[403]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[404]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[404]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[405]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[405]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[406]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[406]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[407]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[407]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[408]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[408]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[409]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[409]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[410]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[410]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[411]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[411]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[412]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[412]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[413]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[413]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[414]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[414]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[415]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[415]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[416]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[416]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[417]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[417]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[418]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[418]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[419]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[419]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[420]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[420]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[421]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[421]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[422]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[422]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[423]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[423]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[424]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[424]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[425]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[425]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[426]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[426]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[427]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[427]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[428]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[428]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[429]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[429]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[430]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[430]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[431]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[431]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[432]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[432]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[433]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[433]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[434]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[434]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[435]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[435]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[436]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[436]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[437]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[437]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[438]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[438]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[439]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[439]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[440]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[440]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[441]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[441]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[442]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[442]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[443]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[443]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[444]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[444]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[445]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[445]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[446]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[446]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[447]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[447]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[448]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[448]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[449]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[449]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[450]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[450]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[451]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[451]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[452]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[452]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[453]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[453]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[454]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[454]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[455]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[455]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[456]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[456]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[457]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[457]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[458]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[458]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[459]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[459]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[460]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[460]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[461]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[461]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[462]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[462]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[463]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[463]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[464]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[464]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[465]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[465]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[466]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[466]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[467]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[467]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[468]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[468]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[469]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[469]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[470]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[470]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[471]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[471]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[472]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[472]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[473]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[473]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[474]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[474]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[475]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[475]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[476]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[476]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[477]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[477]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[478]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[478]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[479]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[479]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[480]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[480]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[481]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[481]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[482]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[482]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[483]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[483]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[484]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[484]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[485]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[485]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[486]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[486]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[487]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[487]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[488]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[488]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[489]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[489]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[490]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[490]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[491]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[491]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[492]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[492]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[493]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[493]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[494]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[494]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[495]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[495]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[496]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[496]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[497]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[497]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[498]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[498]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[499]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[499]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[500]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[500]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[501]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[501]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[502]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[502]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[503]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[503]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[504]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[504]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[505]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[505]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[506]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[506]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[507]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[507]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[508]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[508]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[509]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[509]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[510]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[510]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[511]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[511]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[512]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[512]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[513]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[513]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[514]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[514]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[515]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[515]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[516]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[516]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[517]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[517]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[518]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[518]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[519]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[519]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[520]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[520]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[521]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[521]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[522]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[522]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[523]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[523]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[524]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[524]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[525]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[525]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[526]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[526]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[527]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[527]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[528]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[528]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[529]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[529]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[530]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[530]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[531]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[531]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[532]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[532]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[533]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[533]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[534]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[534]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[535]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[535]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[536]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[536]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[537]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[537]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[538]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[538]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[539]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[539]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[540]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[540]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[541]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[541]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[542]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[542]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[543]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[543]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[544]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[544]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[545]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[545]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[546]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[546]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[547]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[547]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[548]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[548]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[549]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[549]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[550]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[550]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[551]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[551]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[552]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[552]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[553]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[553]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[554]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[554]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[555]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[555]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[556]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[556]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[557]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[557]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[558]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[558]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[559]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[559]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[560]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[560]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[561]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[561]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[562]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[562]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[563]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[563]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[564]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[564]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[565]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[565]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[566]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[566]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[567]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[567]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[568]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[568]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[569]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[569]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[570]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[570]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[571]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[571]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[572]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[572]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[573]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[573]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[574]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[574]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[575]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[575]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[576]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[576]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[577]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[577]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[578]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[578]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[579]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[579]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[580]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[580]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[581]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[581]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[582]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[582]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[583]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[583]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[584]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[584]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[585]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[585]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[586]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[586]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[587]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[587]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[588]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[588]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[589]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[589]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[590]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[590]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[591]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[591]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[592]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[592]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[593]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[593]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[594]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[594]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[595]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[595]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[596]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[596]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[597]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[597]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[598]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[598]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[599]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[599]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[600]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[600]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[601]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[601]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[602]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[602]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[603]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[603]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[604]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[604]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[605]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[605]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[606]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[606]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[607]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[607]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[608]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[608]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[609]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[609]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[610]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[610]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[611]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[611]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[612]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[612]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[613]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[613]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[614]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[614]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[615]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[615]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[616]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[616]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[617]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[617]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[618]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[618]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[619]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[619]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[620]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[620]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[621]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[621]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[622]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[622]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[623]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[623]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[624]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[624]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[625]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[625]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[626]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[626]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[627]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[627]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[628]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[628]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[629]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[629]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[630]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[630]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[631]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[631]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[632]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[632]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[633]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[633]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[634]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[634]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[635]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[635]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[636]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[636]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[637]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[637]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[638]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[638]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[639]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[639]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[640]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[640]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[641]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[641]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[642]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[642]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[643]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[643]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[644]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[644]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[645]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[645]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[646]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[646]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[647]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[647]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[648]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[648]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[649]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[649]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[650]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[650]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[651]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[651]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[652]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[652]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[653]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[653]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[654]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[654]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[655]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[655]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[656]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[656]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[657]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[657]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[658]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[658]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[659]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[659]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[660]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[660]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[661]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[661]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[662]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[662]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[663]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[663]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[664]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[664]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[665]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[665]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[666]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[666]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[667]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[667]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[668]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[668]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[669]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[669]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[670]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[670]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[671]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[671]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[672]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[672]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[673]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[673]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[674]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[674]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[675]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[675]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[676]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[676]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[677]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[677]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[678]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[678]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[679]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[679]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[680]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[680]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[681]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[681]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[682]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[682]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[683]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[683]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[684]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[684]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[685]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[685]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[686]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[686]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[687]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[687]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[688]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[688]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[689]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[689]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[690]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[690]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[691]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[691]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[692]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[692]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[693]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[693]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[694]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[694]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[695]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[695]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[696]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[696]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[697]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[697]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[698]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[698]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[699]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[699]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[700]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[700]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[701]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[701]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[702]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[702]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[703]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[703]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[704]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[704]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[705]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[705]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[706]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[706]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[707]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[707]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[708]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[708]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[709]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[709]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[710]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[710]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[711]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[711]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[712]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[712]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[713]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[713]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[714]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[714]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[715]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[715]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[716]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[716]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[717]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[717]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[718]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[718]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[719]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[719]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[720]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[720]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[721]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[721]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[722]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[722]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[723]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[723]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[724]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[724]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[725]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[725]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[726]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[726]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[727]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[727]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[728]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[728]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[729]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[729]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[730]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[730]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[731]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[731]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[732]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[732]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[733]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[733]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[734]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[734]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[735]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[735]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[736]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[736]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[737]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[737]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[738]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[738]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[739]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[739]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[740]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[740]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[741]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[741]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[742]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[742]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[743]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[743]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[744]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[744]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[745]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[745]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[746]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[746]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[747]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[747]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[748]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[748]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[749]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[749]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[750]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[750]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[751]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[751]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[752]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[752]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[753]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[753]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[754]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[754]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[755]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[755]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[756]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[756]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[757]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[757]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[758]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[758]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[759]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[759]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[760]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[760]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[761]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[761]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[762]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[762]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[763]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[763]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[764]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[764]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[765]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[765]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[766]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[766]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[767]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[767]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[768]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[768]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[769]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[769]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[770]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[770]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[771]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[771]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[772]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[772]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[773]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[773]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[774]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[774]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[775]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[775]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[776]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[776]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[777]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[777]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[778]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[778]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[779]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[779]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[780]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[780]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[781]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[781]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[782]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[782]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[783]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[783]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[784]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[784]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[785]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[785]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[786]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[786]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[787]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[787]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[788]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[788]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[789]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[789]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[790]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[790]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[791]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[791]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[792]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[792]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[793]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[793]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[794]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[794]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[795]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[795]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[796]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[796]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[797]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[797]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[798]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[798]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[799]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[799]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[800]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[800]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[801]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[801]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[802]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[802]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[803]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[803]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[804]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[804]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[805]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[805]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[806]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[806]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[807]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[807]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[808]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[808]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[809]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[809]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[810]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[810]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[811]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[811]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[812]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[812]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[813]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[813]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[814]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[814]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[815]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[815]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[816]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[816]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[817]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[817]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[818]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[818]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[819]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[819]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[820]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[820]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[821]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[821]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[822]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[822]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[823]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[823]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[824]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[824]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[825]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[825]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[826]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[826]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[827]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[827]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[828]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[828]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[829]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[829]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[830]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[830]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[831]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[831]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[832]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[832]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[833]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[833]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[834]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[834]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[835]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[835]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[836]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[836]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[837]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[837]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[838]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[838]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[839]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[839]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[840]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[840]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[841]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[841]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[842]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[842]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[843]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[843]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[844]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[844]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[845]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[845]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[846]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[846]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[847]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[847]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[848]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[848]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[849]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[849]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[850]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[850]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[851]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[851]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[852]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[852]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[853]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[853]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[854]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[854]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[855]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[855]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[856]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[856]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[857]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[857]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[858]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[858]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[859]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[859]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[860]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[860]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[861]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[861]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[862]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[862]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[863]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[863]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[864]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[864]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[865]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[865]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[866]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[866]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[867]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[867]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[868]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[868]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[869]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[869]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[870]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[870]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[871]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[871]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[872]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[872]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[873]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[873]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[874]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[874]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[875]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[875]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[876]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[876]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[877]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[877]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[878]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[878]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[879]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[879]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[880]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[880]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[881]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[881]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[882]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[882]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[883]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[883]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[884]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[884]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[885]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[885]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[886]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[886]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[887]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[887]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[888]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[888]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[889]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[889]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[890]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[890]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[891]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[891]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[892]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[892]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[893]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[893]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[894]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[894]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[895]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[895]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[896]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[896]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[897]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[897]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[898]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[898]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[899]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[899]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[900]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[900]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[901]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[901]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[902]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[902]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[903]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[903]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[904]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[904]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[905]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[905]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[906]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[906]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[907]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[907]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[908]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[908]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[909]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[909]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[910]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[910]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[911]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[911]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[912]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[912]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[913]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[913]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[914]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[914]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[915]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[915]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[916]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[916]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[917]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[917]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[918]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[918]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[919]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[919]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[920]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[920]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[921]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[921]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[922]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[922]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[923]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[923]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[924]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[924]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[925]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[925]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[926]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[926]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[927]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[927]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[928]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[928]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[929]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[929]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[930]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[930]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[931]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[931]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[932]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[932]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[933]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[933]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[934]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[934]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[935]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[935]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[936]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[936]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[937]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[937]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[938]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[938]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[939]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[939]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[940]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[940]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[941]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[941]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[942]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[942]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[943]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[943]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[944]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[944]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[945]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[945]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[946]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[946]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[947]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[947]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[948]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[948]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[949]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[949]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[950]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[950]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[951]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[951]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[952]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[952]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[953]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[953]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[954]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[954]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[955]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[955]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[956]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[956]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[957]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[957]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[958]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[958]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[959]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[959]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[960]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[960]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[961]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[961]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[962]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[962]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[963]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[963]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[964]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[964]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[965]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[965]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[966]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[966]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[967]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[967]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[968]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[968]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[969]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[969]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[970]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[970]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[971]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[971]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[972]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[972]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[973]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[973]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[974]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[974]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[975]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[975]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[976]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[976]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[977]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[977]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[978]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[978]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[979]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[979]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[980]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[980]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[981]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[981]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[982]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[982]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[983]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[983]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[984]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[984]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[985]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[985]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[986]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[986]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[987]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[987]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[988]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[988]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[989]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[989]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[990]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[990]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[991]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[991]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[992]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[992]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[993]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[993]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[994]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[994]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[995]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[995]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[996]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[996]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[997]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[997]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[998]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[998]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[999]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[999]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1000]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1000]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1001]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1001]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1002]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1002]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1003]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1003]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1004]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1004]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1005]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1005]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1006]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1006]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1007]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1007]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1008]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1008]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1009]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1009]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1010]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1010]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1011]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1011]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1012]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1012]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1013]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1013]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1014]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1014]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1015]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1015]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1016]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1016]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1017]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1017]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1018]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1018]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1019]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1019]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1020]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1020]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1021]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1021]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1022]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1022]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1023]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1023]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.maf_buf[1024]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.maf_buf[1024]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].x1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].x1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].x2[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].x2[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].x2[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].x2[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].x2[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].x2[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].x2[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].x2[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].xnch[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].xnch[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].xnch[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].xnch[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].xnch[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].xnch[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].xnch[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].xnch[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2].out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2].out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit.var[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit.var[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.fit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.fit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.kp_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.kp_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.fn_fst_6))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.fn_fst_6));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.fn_sec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.fn_sec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.abs_rat_6))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.abs_rat_6));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.pos_rat_6))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.pos_rat_6));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.neg_rat_6))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.neg_rat_6));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.kp_fst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.kp_fst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.kp_sec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.kp_sec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.kp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.kp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.po_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.po_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm.po_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm.po_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.err))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.err));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.xwkp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.xwkp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.spdr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.spdr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.mot_pos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.mot_pos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.mot_pos_lst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.mot_pos_lst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl.dpos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl.dpos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ctl))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ctl));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.kgv_6))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.kgv_6));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.kga_6))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.kga_6));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.un_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.un_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.tfa))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.tfa));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.tfv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.tfv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.kfa))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.kfa));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.kfv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.kfv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.kdp_to_spd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.kdp_to_spd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm.kdv_to_tqr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm.kdv_to_tqr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.spdr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.spdr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.spdr_lst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.spdr_lst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd.tqr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd.tqr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.ffd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.ffd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.usr_mode))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.usr_mode));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.sev_mode_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.sev_mode_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.sev_mode))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.sev_mode));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.pov_mode))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.pov_mode));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.psrc_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.psrc_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.posr_dir))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.posr_dir));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.fix_pos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.fix_pos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.zcap_pos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.zcap_pos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.fix_err_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.fix_err_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.fix_pos_times))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.fix_pos_times));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vsrc_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vsrc_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.velr_dir))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.velr_dir));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vpacc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vpacc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vpdec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vpdec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set_inx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set_inx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.stop_vel_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.stop_vel_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[4]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[4]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[5]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[5]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[6]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[6]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[7]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[7]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[8]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.vcmd_set[8]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm.cmd_src_sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm.cmd_src_sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.stop_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.stop_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.vcmd_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.vcmd_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.abs_spd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.abs_spd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.fix_pos_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.fix_pos_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.fix_pos_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.fix_pos_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.pcmd_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.pcmd_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.pcmd_in_lst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.pcmd_in_lst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.pcmd_fix))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.pcmd_fix));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.fix_pos_err))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.fix_pos_err));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.dpcmd_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.dpcmd_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.dpcmd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.dpcmd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.pcmd_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.pcmd_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.pcmd_out_lst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.pcmd_out_lst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.ctl_word.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.ctl_word.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.ctl_word.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.ctl_word.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.ctl_word))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.ctl_word));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.sts_word.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.sts_word.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.sts_word.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.sts_word.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq.sts_word))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq.sts_word));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.seq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.seq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.pshlx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.pshlx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.rot_res))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.rot_res));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.ts))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.ts));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.insel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.insel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.accrate))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.accrate));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.decrate))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.decrate));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.osvpm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.osvpm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.maxspd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.maxspd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.maxvp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.maxvp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.vpacc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.vpacc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.vpdec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.vpdec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.vpamx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.vpamx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.vparx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.vparx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm.vpapx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm.vpapx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.endf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.endf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.vpx))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.vpx));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.vpxrem))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.vpxrem));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.avp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.avp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.n))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.n));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.rem))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.rem));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.pcmd_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.pcmd_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var.pcmd_err))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var.pcmd_err));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr.var))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr.var));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.mkr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.mkr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.sel))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.sel));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.mask_flag.all));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.mask_flag.bit));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.mask_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.mask_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.anu[0]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.anu[0]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.anu[1]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.anu[1]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.anu[2]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.anu[2]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.anu[3]))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.anu[3]));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.a))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.a));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.b))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.b));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.k1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.k1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.k2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.k2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.g1))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.g1));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm.g2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm.g2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.pcmda))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.pcmda));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.pcmdb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.pcmdb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.pcmd_rem))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.pcmd_rem));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.pls_rem))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.pls_rem));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.pfbk_rem))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.pfbk_rem));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.pera))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.pera));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear.perb))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear.perb));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos.gear))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos.gear));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->pos))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->pos));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm.pos_adj_tims))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm.pos_adj_tims));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm.pobk_mes_times))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm.pobk_mes_times));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm.pobk_mes_lim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm.pobk_mes_lim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm.pobk_ud_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm.pobk_ud_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm.pobk_delay_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm.pobk_delay_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm.pobk_lim_divs))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm.pobk_lim_divs));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm.pos_adj_mod))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm.pos_adj_mod));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.curr_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.curr_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pos_adj_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pos_adj_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pos_dp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pos_dp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pos_dn))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pos_dn));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pos_qp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pos_qp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pos_qn))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pos_qn));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pos_adj_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pos_adj_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pobk_mes_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pobk_mes_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pobk_hold_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pobk_hold_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pobk_mes_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pobk_mes_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.pobk_mes_ud))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.pobk_mes_ud));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.ib_pha_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.ib_pha_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj.ic_pha_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj.ic_pha_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mfj))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mfj));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.mode))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.mode));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.Ld))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.Ld));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.Lq))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.Lq));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.Rm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.Rm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.PPN))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.PPN));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.Jall))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.Jall));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.Jrat))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.Jrat));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.Dm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.Dm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.PHIm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.PHIm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm.Kti))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm.Kti));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.pm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.pm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Lm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Lm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Ls))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Ls));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Lr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Lr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Rs))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Rs));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Rr))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Rr));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.PPN))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.PPN));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Jall))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Jall));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Jrat))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Jrat));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Dm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Dm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im.Kti))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im.Kti));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.im))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.im));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.kpc_reg))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.kpc_reg));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.kic_reg))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.kic_reg));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.fnc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.fnc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.tic))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.tic));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.kpc))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.kpc));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.kic))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.kic));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.co_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.co_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.co_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.co_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.ci_ulim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.ci_ulim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.ci_llim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.ci_llim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.fnv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.fnv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl.tiv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl.tiv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ctl))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ctl));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.style))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.style));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.icr_ls_amp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.icr_ls_amp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.icr_rs_fst))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.icr_rs_fst));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.icr_rs_sec))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.icr_rs_sec));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.icr_tf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.icr_tf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.icr_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.icr_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.icr_ramp_step))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.icr_ramp_step));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.delay_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.delay_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.kua_to_ls))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.kua_to_ls));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.kua_to_rs))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.kua_to_rs));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.rs_avg_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.rs_avg_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.rs_delay_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.rs_delay_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.velr_amp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.velr_amp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.velr_tf))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.velr_tf));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.velr_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.velr_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.velr_ramp_step))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.velr_ramp_step));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.uq_avg_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.uq_avg_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.uq_delay_tim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.uq_delay_tim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.velr_ramp_step2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.velr_ramp_step2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.uq_avg_num2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.uq_avg_num2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.uq_delay_tim2))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.uq_delay_tim2));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.kiq_to_jm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.kiq_to_jm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.kuq_to_phim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.kuq_to_phim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.kiq_to_phim))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.kiq_to_phim));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.cycle_tims))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.cycle_tims));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.cycle_num))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.cycle_num));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref.ramp_step))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref.ramp_step));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm.ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm.ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.prm))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.prm));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.kgv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.kgv));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.exci_in))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.exci_in));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.exci_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.exci_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.exci_out))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.exci_out));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.exci_end_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.exci_end_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.tim_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.tim_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.cyc_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.cyc_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.ia))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.ia));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.ia_ref))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.ia_ref));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.ua))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.ua));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.ia_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.ia_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.iai_s))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.iai_s));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.lrp_state))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.lrp_state));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.ua_sum))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.ua_sum));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.ua_sum_low))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.ua_sum_low));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.ua_sum_high))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.ua_sum_high));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.jdp_state))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.jdp_state));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.iq_sum))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.iq_sum));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.uq_sum))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.uq_sum));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.iq_ur_sum))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.iq_ur_sum));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.phim_tmp))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.phim_tmp));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.delay_cnt))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.delay_cnt));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd.finish_flag))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd.finish_flag));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj->mpd))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj->mpd));

  tmp = (((unsigned int)(&(gSevDrv.sev_obj))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj));

  tmp = (((unsigned int)(&(gSevDrv))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gSevDrv));

  tmp = (((unsigned int)(&(gAuxFunc.prm->aux_mask_flag.all))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.prm->aux_mask_flag.all));

  tmp = (((unsigned int)(&(gAuxFunc.prm->aux_mask_flag.bit))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.prm->aux_mask_flag.bit));

  tmp = (((unsigned int)(&(gAuxFunc.prm->aux_mask_flag))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.prm->aux_mask_flag));

  tmp = (((unsigned int)(&(gAuxFunc.prm))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.prm));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.cur_index))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.cur_index));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd0_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd0_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd0_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd0_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd1_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd1_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd1_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd1_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd2_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd2_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd2_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd2_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd3_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd3_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd3_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd3_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd4_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd4_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd4_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd4_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd5_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd5_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd5_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd5_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd6_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd6_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd6_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd6_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd7_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd7_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd7_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd7_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd8_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd8_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd8_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd8_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd9_h))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd9_h));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd.alm_cd9_l))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd.alm_cd9_l));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCd))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCd));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[0]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[0]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[1]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[1]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[2]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[2]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[3]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[3]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[4]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[4]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[5]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[5]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[6]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[6]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[7]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[7]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[8]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[8]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[9]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[9]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode.almCodeArray[10]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode.almCodeArray[10]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almcode))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almcode));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_oc_0_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_oc_0_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_ov_1_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_ov_1_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_uv_2_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_uv_2_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_brkph_3_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_brkph_3_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_reserr_4_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_reserr_4_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_ol_5_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_ol_5_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_ot_6_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_ot_6_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_ioerr_7_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_ioerr_7_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_reg_8_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_reg_8_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_ps_9_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_ps_9_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_os_10_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_os_10_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_opre_11_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_opre_11_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_dir_12_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_dir_12_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_soc_13_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_soc_13_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_obph_14_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_obph_14_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd0_15_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd0_15_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd1_16_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd1_16_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd2_17_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd2_17_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd3_18_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd3_18_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd4_19_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd4_19_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd5_20_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd5_20_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd6_21_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd6_21_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd7_22_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd7_22_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd8_23_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd8_23_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd9_24_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd9_24_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd10_25_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd10_25_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd11_26_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd11_26_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd12_27_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd12_27_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd13_28_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd13_28_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd14_29_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd14_29_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd15_30_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd15_30_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd16_31_tim))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm.alm_rsvd16_31_tim));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTm))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTm));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[0]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[0]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[1]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[1]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[2]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[2]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[3]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[3]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[4]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[4]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[5]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[5]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[6]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[6]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[7]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[7]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[8]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[8]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[9]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[9]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[10]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[10]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[11]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[11]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[12]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[12]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[13]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[13]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[14]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[14]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[15]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[15]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[16]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[16]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[17]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[17]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[18]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[18]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[19]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[19]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[20]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[20]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[21]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[21]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[22]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[22]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[23]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[23]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[24]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[24]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[25]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[25]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[26]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[26]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[27]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[27]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[28]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[28]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[29]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[29]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[30]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[30]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[31]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[31]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes.almTimArray[32]))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes.almTimArray[32]));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm.almtimes))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm.almtimes));

  tmp = (((unsigned int)(&(gAuxFunc.log->prm))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->prm));

  tmp = (((unsigned int)(&(gAuxFunc.log->alm_flag_lst))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log->alm_flag_lst));

  tmp = (((unsigned int)(&(gAuxFunc.log))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc.log));

  tmp = (((unsigned int)(&(gAuxFunc))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); 
  fprintf(fp,"0x%0 8x %6d    %s \t\n",tmp,tmp,VNAME(gAuxFunc));

  //axis offset
	  fprintf(fp,"%s \t\n","axis offset start");
  for (i = 1; i < SERVO_AXIS_NUM; i++)
  {
  fprintf(fp,"%s%d \t\n","axis",i);

	  tmp = ((unsigned int)(&(gSevDrv.sev_chd[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_chd[0])) & 0xffffffff); 
	  fprintf(fp,"0x%0 8x %6d    %s%d%s-%s \t\n",tmp,tmp,VNAME(gSevDrv.sev_chd[),i,"]",VNAME(gSevDrv.sev_chd[0]));
	  tmp = ((unsigned int)(&(gSevDrv.sev_task[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_task[0])) & 0xffffffff); 
	  fprintf(fp,"0x%0 8x %6d    %s%d%s-%s \t\n",tmp,tmp,VNAME(gSevDrv.sev_task[),i,"]",VNAME(gSevDrv.sev_task[0]));
	  tmp = ((unsigned int)(&(gSevDrv.sev_obj[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_obj[0])) & 0xffffffff); 
	  fprintf(fp,"0x%0 8x %6d    %s%d%s-%s \t\n",tmp,tmp,VNAME(gSevDrv.sev_obj[),i,"]",VNAME(gSevDrv.sev_obj[0]));
	  tmp = ((unsigned int)(&(gAuxFunc.prm[i])) & 0xffffffff) - ((unsigned int)(&(gAuxFunc.prm[0])) & 0xffffffff); 
	  fprintf(fp,"0x%0 8x %6d    %s%d%s-%s \t\n",tmp,tmp,VNAME(gAuxFunc.prm[),i,"]",VNAME(gAuxFunc.prm[0]));
	  tmp = ((unsigned int)(&(gAuxFunc.log[i])) & 0xffffffff) - ((unsigned int)(&(gAuxFunc.log[0])) & 0xffffffff); 
	  fprintf(fp,"0x%0 8x %6d    %s%d%s-%s \t\n",tmp,tmp,VNAME(gAuxFunc.log[),i,"]",VNAME(gAuxFunc.log[0]));

  }
  fprintf(fp,"%s \t\n","axis offset end");

  fclose(fp);

  return 0;
}
