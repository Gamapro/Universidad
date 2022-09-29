const App = () => {

    const ProgressBar = () => {
      const [progress, setProgress] = React.useState(0);
      const [docType, setDocType] = React.useState('');
      const [name, setName] = React.useState('');
      const [category, setCategory] = React.useState('');
      const [email, setEmail] = React.useState('');
  
      React.useEffect(() => {
          let value = 0;
          if(docType !== '') value += 25;
          if(category !== '') value += 25;
          if(name !== '' && name.length >= 2 && name.length <= 32) value += 25;
          if(email !== '' && email.length <= 128 && email.match(/^[a-z0-9]+([\.]?[a-z0-9]+)*@[a-z0-9]+([\.]?[a-z0-9]+)*(\.[a-z0-9]{2,3})+$/)) value += 25;
          setProgress(value);
      }, [email, docType, name, category]); 
  
      return(
        <div>
          <div className="form-progress-bar-wrapper">
            <div className="form-progress-bar" style={{width: `${progress}%`}}></div>
          </div>
          <div>
            <label htmlFor="docType">Document Type</label>
            <select className="form-control" id="documentType" value={docType} onChange={(e) => setDocType(e.target.value)}>
              <option value=""></option>
              <option value="Plain">Plain</option>
              <option value="PDF">PDF</option>
            </select>
          </div>
          <div>
            <label htmlFor="name">Document Name</label>
            <input className="form-control" type="text" id="documentName" value={name} onChange={(e) => setName(e.target.value)}/>
          </div>  
          <div>
            <label htmlFor="category">Category</label>
            <select className="form-control" id="category" value={category} onChange={(e) => setCategory(e.target.value)}>
              <option value=""></option>
              <option value="Audit">Audit</option>
              <option value="Application">Application</option>
              <option value="Other">Other</option>
            </select>
          </div>
          <div>
            <label htmlFor="mail">Email</label>
            <input className="form-control" type="email" id="email" value={email} onChange={(e) => setEmail(e.target.value)}/>
          </div>  
        </div>
      );
    }
    
    return (
      <div>
        <ProgressBar/>
      </div>
    );
    
  }
  
  ReactDOM.render(
    <App />,
    document.getElementById('app')
  );
  