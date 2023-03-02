#include <pspkernel.h>
#include <pspdebug.h>
#include <stdlib.h>
#include <string>

PSP_MODULE_INFO("Hello String", 0, 1,0);

int exit_callback(int arg1, int arg2, void *common)
{
  sceKernelExitGame();
  return 0;
}

int CallbackThreadEntry(SceSize n, void* argp)
{
  int callback_id = sceKernelCreateCallback("Exit Callback", exit_callback,NULL);

  if(callback_id >= 0)
    sceKernelRegisterExitCallback(callback_id);
  sceKernelSleepThreadCB();
  return 0;
}

void setup_exit_callback()
{
  int thread_id = sceKernelCreateThread("Exit Thread", CallbackThreadEntry, 0x18, 0xFA0,0,0);

  if(thread_id >= 0)
    {
      sceKernelStartThread(thread_id,0,NULL);
    }
}

int main(void)
{
  setup_exit_callback();
  pspDebugScreenInit();

  std::string hello = "Hello String";

  while(1)
  {
    pspDebugScreenPrintf(hello.c_str());
    sceKernelDelayThread(1000000);
  }
  return 0;
}
