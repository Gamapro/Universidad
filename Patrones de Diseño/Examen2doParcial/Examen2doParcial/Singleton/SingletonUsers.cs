using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Newtonsoft.Json;
using System.Diagnostics;
using Newtonsoft.Json.Linq;

namespace Examen2doParcial
{
    class SingletonUsers
    {
        private string test_user, test_pass;
        private static SingletonUsers _instance = null;
        // this field holds the lock handle for thread locking
        private static object _handle = new object();
        private static Data data = new Data();

        protected SingletonUsers()
        {
            // read json
            data = JsonConvert.DeserializeObject<Data>(File.ReadAllText("../../../json_data.json"));
            // read json
            this.test_user = "admin";
            this.test_pass = "12345";
        }

        public bool validateTestUser(string user, string password)
        {
            return (this.test_user == user && this.test_pass == password);
        }

        public bool validateUser(string user, string password, ref Alumno alumnoLogin)
        {
            foreach (Alumno alumno in data.Alumnos)
            {
                if (alumno.Mail == user && alumno.Password == password)
                {
                    alumnoLogin = alumno;
                    return true;
                }
            }
            return false; 
        }

        public static SingletonUsers Instance
        {
            get
            {
                // thread-safe lazy initialization
                // remove this lock statement if your code is not multi-threaded
                lock (_handle)
                {
                    if (_instance == null)
                    {
                        _instance = new SingletonUsers();
                    }
                }
                return _instance;
            }
        }

        public static SingletonUsers GetInstance()
        {
            if (_instance == null)
            {
                _instance = new SingletonUsers();
            }
            return _instance;
        }

        public string[] getGrades()
        {
            return data.Materias;
        }

    }
}
