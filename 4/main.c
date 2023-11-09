

#include "thread_pool.h"


#define CPU_TOTAL_NUCLEUS 4

typedef struct  
{
	char name[16];
	int age;
}para_t;

para_t args = {
	"wahaha",
	18
};


void task_function(void *para) {

	para_t *temp = (para_t *)para;
	//tp_sleep(3000);
	printf("process task :name--%s, age:%d , thread_id: %lu --- success.\n", temp->name, temp->age, get_self_thread_id());
}

void exit_function(void *para) {

//	printf("enter exit functin.\n");
	

//	printf("leave exit functin.\n");
}

void time_out_function(void *para) {

	printf("********thread  time out ******** \n");
}

int main(int argc, char *argv[])
{
	{
		int task = 1000000000;
		
		//�����̳߳�
		thread_pool_t *pool = createThreadPool(CPU_TOTAL_NUCLEUS<<2, CPU_TOTAL_NUCLEUS<<2);
		
		while (task--)
		{
			time_out_t time_out = {time_out_function, 2};
			
			if (!addJobToThreadPoolEx(pool, task_function	, exit_function, &args, &time_out)) {
				printf("------------- err ----------\n");
				break;
			}
			
			//tp_sleep(1);
		}
		
		
		getchar();
		
		//�����̳߳�
		destroyThreadPool(pool);
		
		getchar();
		return 0;
	}
}


//ʹ�÷�ʽ
/*
1������ͷ�ļ�thread_pool.h
2������createThreadPool�����̳߳�
	�̳߳ز�����fix_thread_num, �����߳�����Ҳ������С�̳߳���������ĸ���ΪCPU����*2
				max_thread_num, ����߳������̳߳ض�̬�����߳�ʱ���ܳ�����ֵ�����ݷ��������ؾ���
3������������̳߳�
		��ʽһ��
					addJobToThreadPool��
					������pool,�̳߳ؾ��
						  process_job, �û�������
						  args���û�����������
		��ʽ����
					 addJobToThreadPoolEx,
					 ��addJobToThreadPool�Ļ����ϼ��볬ʱ�趨

4�������̳߳أ�destroyThreadPool


*/


