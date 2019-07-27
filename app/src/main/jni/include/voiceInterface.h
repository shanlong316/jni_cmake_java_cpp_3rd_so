#ifndef _VOICE_INTERFACE_H_
#define _VOICE_INTERFACE_H_
#ifdef __cplusplus
extern "C" {
#endif
typedef void *VoiceHandle;
extern void voiceInit(VoiceHandle *handle);
extern void voiceSetParams(VoiceHandle handle,char *name,void *value);
extern void voiceDestroy(VoiceHandle handle);
extern void voiceReset(VoiceHandle handle); 
extern void voiceSetDoaDir(VoiceHandle handle,char *doaDir);
extern char *voiceGetOriginal(VoiceHandle handle,int doa);
extern int voiceProcessContainPreparation(VoiceHandle handle,char *input,short *output); 
#ifdef __cplusplus
}
#endif
#endif
